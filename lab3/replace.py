#!/bin/python

import os
import re

for dir_, subdir, files in os.walk('./'):
	for f in files:
		if (f.endswith('.cpp') or f.endswith('.h')) and 'build/' not in dir_:
			p = os.path.relpath(dir_, './') + f'/{f}'
			with open(p, 'r+') as o:
				contents = o.read()
				print(re.findall('\s_.*\;+', contents))
				break

