import os
import random
import time
import subprocess
import sys

v = time.clock()
t = 0
y = 0
n = 0
multa = -1
if (len(sys.argv) < 2):
    print "Usage: test_gen.py operator nbr_of_digits[0:1000]"
    exit(1);
op = sys.argv[1]
if (len(sys.argv) > 2):
    multa = int(sys.argv[2])
if (multa > 1000):
    print "Usage: nbr_of_digits must be positiv and less than 1000"
    exit(1);
while (1):
    if (multa == -1):
        mult = random.randint(1, 100);
    else:
        mult = multa
    a = random.randint(-int('9'*mult),int('9'*mult))
    b = random.randint(-int('9'*mult),int('9'*mult))
    ##
    p1 = subprocess.Popen(["echo", "("+str(a)+")"+sys.argv[1]+"("+str(b)+")"], stdout=subprocess.PIPE)
    p2 = subprocess.Popen(["./../calc", "0123456789", "()+-*/%", str(len(str(a))+len(str(b))+5)], stdin=p1.stdout, stdout=subprocess.PIPE)
    v = time.clock()
    out1 = p2.communicate()[0]
    t += time.clock() - v
    ##
    p1 = subprocess.Popen(["echo", "("+str(a)+")"+sys.argv[1]+"("+str(b)+")"], stdout=subprocess.PIPE)
    p2 = subprocess.Popen(["bc"], stdin=p1.stdout, stdout=subprocess.PIPE)
    v = time.clock()
    out2 = p2.communicate()[0]
    y += time.clock() - v
    out1 = out1.replace('\n', '')
    out2 = out2.replace('\n', '')
    out2 = out2.replace('\\', '')
    if (out1 != out2):
        print a, b
        print (out1+ " : "+out2)
        exit(1)
    else:
        n += 1
        print n, "|", "("+str(a)+")"+sys.argv[1]+"("+str(b)+")","=",out1
