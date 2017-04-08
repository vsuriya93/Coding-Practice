# Enter your code here. Read input from STDIN. Print output to STDOUT
line1=raw_input()
line2=raw_input()
if len(line1)<=len(line2):
    big=line2
    small=line1
else:
    big=line1
    small=line2
big=list(big)
small=list(small)
count=0
x=0
while(x<len(big)):
    val=big[x]
    if big[x] not in small:
        temp=big
        big=filter(lambda a: a!=big[x],big)
        count+=len(temp)-len(big)
    else:    
        del small[small.index(big[x])]
        del big[x]
print len(small)+count