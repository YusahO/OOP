#!/bin/python

import os

def any_header(li):
    for elem in li:
        if elem.endswith('.h'):
            return True
    return False

print('''
cmake_minimum_required(VERSION 3.0.0)
project(lab3 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui/)
''')

print('set(src_files')
for dir_, subdir, files in os.walk('./'):
    # print(dir_, subdir, files)
    # if (any_header(files)):
    #     print(f'target_include_directories(lab3 PUBLIC {dir_})')
    for f in files:
        if f.endswith('.cpp') and 'build/' not in dir_:
            print('"' + dir_ + '/' + f + '"')
print(')')

print('''
add_executable(lab3
    ${src_files}
)''')

for dir_, subdir, files in os.walk('./'):
    if 'build/' not in dir_ and (any_header(files)):
        print(f'target_include_directories(lab3 PUBLIC {dir_})')

print('''
find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_link_libraries(lab3 Qt5::Widgets)
target_include_directories(lab3 PUBLIC include)
''')
