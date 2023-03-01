import sys

filename = sys.argv[1]

mshfile = filename.replace(".obj", ".msh")

vsect = False
fsect = False

vcnt = 0
fcnt = 0
with open(mshfile, "w") as d, open(filename, "r") as s:
    for l in s:
        if l.startswith("v "):
            vcnt += 1
        if l.startswith("f "):
            fcnt += 1

with open(mshfile, "w") as d, open(filename, "r") as s:
    for l in s:
        if l.startswith("v "):
            if not vsect:
                d.write(f'{vcnt}\n')
                vsect = True
            d.write(l[2:])

        if l.startswith("f "):
            if not fsect:
                d.write(f'\n{fcnt}\n')
                fsect = True
            line = list(map(lambda x: x.split('/')[0], l[2:].strip().split()))
            d.write(' '.join(line) + '\n')