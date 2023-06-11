#!/bin/python

import sys
if len(sys.argv) != 3:
    print("error: not enough arguments")
    exit(1)

input_fname = sys.argv[1]
output_fname = sys.argv[2]
input_data = open(input_fname, 'r').readlines()
v_n = len(list(filter(lambda x: x.startswith('v '), input_data)))
f_n = len(list(filter(lambda x: x.startswith('f '), input_data)))
output_stream = open(output_fname, 'w')
was_v, was_f = False, False
# print(f'{v_n} {f_n}', file=output_stream)
for line in input_data:
    content = line.strip().split()
    if content[0] == 'v':
        if not was_v:
            print(v_n, file=output_stream)
            was_v = True
        print(f'{content[1]} {content[2]} {content[3]}', file=output_stream)
    elif content[0] == 'f':
        if not was_f:
            print(f_n * 3, file=output_stream)
            was_f = True
        one = content[1].split('/')[0]
        two = content[2].split('/')[0]
        three = content[3].split('/')[0]
        print(f'{one} {two}', file=output_stream)
        print(f'{two} {three}', file=output_stream)
        print(f'{one} {three}', file=output_stream)
