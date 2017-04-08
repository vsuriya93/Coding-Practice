# Enter your code here. Read input from STDIN. Print output to STDOUT
import itertools
n=raw_input()
people,topics=map(int,n.split())
matrix=[]
for r in xrange(0,people):
    temp=raw_input()
    matrix.append(temp)
order=list(itertools.combinations([x for x in xrange(0,people)],r=2))
y=len(order)
count=0
value=[]
for x in xrange(0,y):
    r1,r2=order[x]
    str1=matrix[r1][:]
    str2=matrix[r2][:]
    topics=0
    for i in xrange(0,len(str1)):
        if str1[i]=='0' and str2[i]=='0':
            pass
        else:
            topics+=1
    value.append(topics)
check=max(value)
for i in xrange(0,len(value)):
    if value[i]==check:
        count+=1
print check
print count