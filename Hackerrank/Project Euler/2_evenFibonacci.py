# Enter your code here. Read input from STDIN. Print output to STDOUT
n=input()
for k in range(0,n):
    m=input()
    first=0
    second=1
    output=0
    i=0
    count=0
    while(True):
        third=first+second
        if third%2==0 and third<=m:
            count+=third
        elif third>m:
            break
        first=second
        second=third
    print count