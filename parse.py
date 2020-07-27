import sys
import re
import os

s = ""
fname = sys.argv[1]

with open(fname, "r") as f:
    s = f.read()

fname = fname.replace(".", "_generated.")

r = re.compile("#include *(<.+>)|(\".+\")")
s = r.sub('', s)
with open(fname, "w") as f:
    f.write(s)

os.system("clang++ -Xclang -ast-dump=json -fsyntax-only {} 1> test.json".format(fname))
os.remove(fname)
