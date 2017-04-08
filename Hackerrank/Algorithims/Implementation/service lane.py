# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
n=map(int,n.split(' '))
testCase=n[1]
length=n[0]
width=raw_input()
width=map(int,width.split(' '))
for i in range(0,testCase):
    value=raw_input()
    value=map(int,value.split(' '))
    entry=value[0]
    exit=value[1]
    output=width[entry]
    for ctr in xrange(entry,exit+1):
        if output>width[ctr]:
            output=width[ctr]
    print output