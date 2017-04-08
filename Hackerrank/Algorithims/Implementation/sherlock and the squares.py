# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
n=raw_input()
n=int(n)
for i in range(0,n):
    lst=raw_input()
    lst=map(int,lst.split(' '))
    a=lst[0]
    b=lst[1]
    count=0
    flag=0
    k=a
    jump=1
    while(True):
        val=math.sqrt(k)
        if val==math.floor(math.sqrt(k)):
            count+=1
            jump=2*val-1
            k+=jump
        else:
            k+=1
        #print jump,val,k
        if k>b:
            break
    print count