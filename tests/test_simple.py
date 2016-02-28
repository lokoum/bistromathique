import os
import random
import time
import subprocess

dict_test = "dict_test"
n = 0
nbr_lines = sum(1 for line in open(dict_test))
with open(dict_test, "r") as ins:
    for line in ins:
        line = line.replace('\n','')
        p1 = subprocess.Popen(["echo", line], stdout=subprocess.PIPE)
        p2 = subprocess.Popen(["./../calc", "0123456789", "()+-*/%", str(len(line))], stdin=p1.stdout, stdout=subprocess.PIPE)
        out1 = p2.communicate()[0]
        p1 = subprocess.Popen(["echo", line], stdout=subprocess.PIPE)
        p2 = subprocess.Popen(["bc"], stdin=p1.stdout, stdout=subprocess.PIPE)
        out2 = p2.communicate()[0]
        out1 = out1.replace('\n','')
        out2 = out2.replace('\n','')
        print "\n"
        print "-"*50
        if (out1 != out2):
            print "\033[91m"
        else:
            print "\033[92m"
        print "TEST:            ", n, "/", nbr_lines
        print "expr:            ", line
        print "bistromator:     ", out1
        print "bc:              ", out2
        print "\033[0;0m"
        print "-"*50            
        if (out1 != out2):
            exit(1);
        n += 1
print "Tests ok: ",n," GG WellPlay"
        
