# Enter your code here. Read input from STDIN. Print output to STDOUT
import itertools
T=input()
for i in range(0,T):
    n=input()
    a=input()
    b=input()
    output=[]
    for j in xrange(0,n):
        val=j*b+(n-j-1)*a
        if val not in output:
            output.append(val)
    output.sort()
    for x in output:
        print x,
    print 
        