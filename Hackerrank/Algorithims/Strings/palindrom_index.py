# Enter your code here. Read input from STDIN. Print output to STDOUT
temp=raw_input()
T=int(temp)
for x in xrange(T):
    str=raw_input()
    result=-1
    left=0
    right=len(str)-1
    while str[left]==str[right] and left<right :
        left+=1
        right-=1
    for pos in xrange(left,right+1):
        sub_str=str[0:pos]+str[pos+1:]
        if sub_str==sub_str[::-1]:
            result=pos
            break
    print result
