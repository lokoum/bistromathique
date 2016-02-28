from random import random, randint, choice
import os, time, subprocess, sys

class Expression:
    pass

class Number(Expression):
    def __init__(self, num):
        self.num = num

    def __str__(self):
        return str(self.num)

class BinaryExpression(Expression):
    def __init__(self, left, op, right):
        self.left = left
        self.op = op
        self.right = right

    def __str__(self):
        return str(self.left) + self.op + str(self.right)

class ParenthesizedExpression(Expression):
    def __init__(self, exp):
        self.exp = exp

    def __str__(self):
        return "(" + str(self.exp) + ")"

def randomExpression(prob, ap, mult):
    p = random()
    if p > prob:
        return Number(randint(0, int("9"*mult)))
    elif randint(0, 1) == 0:
        return ParenthesizedExpression(randomExpression(prob / ap, ap, mult))
    else:
        left = randomExpression(prob / ap, ap, mult)
        op = choice(["*", "+", "-"])
        right = randomExpression(prob / ap, ap, mult)
        return BinaryExpression(left, op, right)

nbr = 100
mult = 1
multmax = 500
size = 1.1
aff = False
if (len(sys.argv) < 2):
    print "Usage: test_arithmetique prob [nbr_of_digit_max] [nbr_test_per_nbr_of_digit]"
    exit (1);
if (float(sys.argv[1]) < 1.5 and float(sys.argv[1]) > 1.009):
    size = float(sys.argv[1])
else:
    print "Usage: prob must be between 1.01 and 1.5"
    exit (1);

if (len(sys.argv) > 2):
    multmax = int(sys.argv[2])

if (len(sys.argv) > 3):
    nbr = int(sys.argv[3])
    
def calcul(nbr, mult):
    n = 0
    t = 0
    y = 0
    y2 = 0
    t2 = 0
    while (n < nbr):
        n += 1
        a = randomExpression(1, size, mult)
#        print a,"\n\n"
        p1 = subprocess.Popen(["echo", str(a)], stdout=subprocess.PIPE)
        p2 = subprocess.Popen(["./../calc", "0123456789", "()+-*/%", str(len(str(a)))], stdin=p1.stdout, stdout=subprocess.PIPE)
        v = time.clock()
        out1 = p2.communicate()[0]
        t = time.clock() - v
        t2 += t
        p1 = subprocess.Popen(["echo", str(a)], stdout=subprocess.PIPE)
        p2 = subprocess.Popen(["bc"], stdin=p1.stdout, stdout=subprocess.PIPE)
        v = time.clock()
        out2 = p2.communicate()[0]
        y = time.clock() - v
        y2 += y
        out1 = out1.replace('\n','')
        out2 = out2.replace('\n','')
        out2 = out2.replace('\\', '')
        if (out1!= out2):
            print a
            print out1, out2
            exit(1)
    print t2," : ",y2
    if t2 < y2:
        print ("\033[94mMATCH: " + str(mult) +": You Are The Winner!\033[0m")
    else:
        print ("\033[91mMATCH: " + str(mult) +": Sorry guys, you lose...\033[0m")

while (mult < multmax):
    calcul(nbr, mult)
    mult += 1
