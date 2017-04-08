# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
n=int(n)
array=[]
for i in range(0,n):
    a=raw_input()
    temp=map(int,a.split())
    array.append(temp)
d1=0
d2=0
for i in range(0,n):
    for j in range(0,n):
        if i==j:
            d1+=array[i][j]
        if i+j==n-1:           
            d2+=array[i][j]
        else:
            pass
if d1>d2:
    print d1-d2
else:
    print d2-d1