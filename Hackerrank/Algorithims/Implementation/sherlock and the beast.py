# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
m=int(n)
for k in range(0,m):
    n=raw_input()
    n=int(n)
    #print n
    string=''
    flag=0
    if n<3:
        string='-1'
        print string
    else:
        stopVal=(n/3)+1
        for i in xrange(0,stopVal):
            times=5*i
            check=n-times
            #print times,check
            if check<0:
                continue
            elif check%3==0:
                string='5'*check+'3'*times
                flag=1
                break;
        if flag==1:
            print string
        else:
            print '-1'