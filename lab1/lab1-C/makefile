CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra # -Wpedantic -Wfloat-conversion -Wfloat-equal
ARGS := 
VALG := 0
VALG_KEYS := --leak-check=full --show-leak-kinds=all --track-origins=yes -s

SRCS := $(wildcard src/*.c)
UT_SRCS := $(wildcard unit_tests/*.c)
OBJS := $(filter-out out/main.o,$(patsubst src/%.c,out/%.o,$(SRCS)))
OBJS := $(filter-out out/%_lib.o,$(OBJS))

DLIBS := libs/libmesh.so
SLIBS := 

LDFLAGS := -Llibs/
LDLIBS := $(addprefix -l,$(patsubst lib%.a,%,$(wildcard lib*.a)))

export LD_LIBRARY_PATH += libs/

out/ : 
	-mkdir -p out/

out/%.o : */%.c inc/*.h | out/
	$(CC) $(CFLAGS) -I ./inc/ -c $< -o $@

app.exe : $(OBJS) out/main.o $(SLIBS) $(DLIBS)
ifeq ($(LDFLAGS),"-L. ")
	$(CC) $^ -I ./inc/ $(LDFLAGS) $(LDLIBS) -o $@ -lm
else
	$(CC) $^ -I ./inc/ -o $@ -lm
endif

unit_tests.exe : LDLIBS += -lcheck -lpthread -lrt -lm 
unit_tests.exe : $(OBJS) out/check_main.o $(SLIBS) $(DLIBS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

.PHONY: debug release clean func unit run debugger slib dlib

run : app.exe
ifeq ($(VALG),1)
	valgrind $(VALG_KEYS) ./app.exe $(ARGS)
else
	./app.exe $(ARGS)
endif

debugger : debug
ifeq ($(ARGS),)
	gdb app.exe
else
	gdb --args app.exe $(ARGS)
endif

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

func : debug
	-func_tests/scripts/func_tests.sh

unit : OBJS := $(filter-out out/check_main.o,$(patsubst unit_tests/%.c,out/%.o,$(UT_SRCS)))
unit : unit_tests.exe
ifeq ($(VALG),1)
	valgrind $(VALG_KEYS) ./unit_tests.exe
else
	./unit_tests.exe
endif

clean :
	-$(RM) out/* *.exe 

slib : $(SLIBS)

dlib : $(DLIBS)

libs/ :
	mkdir -p libs/

libs/lib%.a : src/%_lib.c | libs/
	gcc -std=c99 -I ./inc/ $(CFLAGS) -c $< -o $(patsubst src/%.c,out/%.o,$<)
	ar rc $@ $(patsubst src/%.c,out/%.o,$<)
	ranlib $@

libs/lib%.so : src/%.c | libs/
	gcc -std=c99 -I ./inc/ $(CFLAGS) -fPIC -c $< -o $(patsubst src/%.c,out/%.o,$<)
	gcc -I ./inc/ -o $@ -shared $(patsubst src/%.c,out/%.o,$<)

libs/libmesh.so : src/*.c | libs/
	gcc -std=c99 -I ./inc/ $(CFLAGS) -fPIC -c src/matrix.c -o out/matrix.o
	gcc -std=c99 -I ./inc/ $(CFLAGS) -fPIC -c src/mesh.c -o out/mesh.o
	gcc -I ./inc/ -o $@ -shared out/matrix.o out/mesh.o