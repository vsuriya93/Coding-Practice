# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
n=int(n)
for i in range(0,n):
    m=raw_input()
    m=int(m)
    output=0
    k=3
    a=(m-1)//3
    b=(m-1)//5
    common=(m-1)/15
    output=(3*(a*(a+1))//2)+(5*(b*(b+1))//2)- (15*(common*(common+1))//2)
    print output