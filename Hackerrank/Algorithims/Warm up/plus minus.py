# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
n=int(n)
array=raw_input()
array=map(int,array.split())
sum=[0]*3
for i in range(0,n):
    if array[i]>0:
        sum[0]+=1
    elif array[i]<0:
        sum[1]+=1
    else :
        sum[2]+=1
for i in range(0,3):
    print float(sum[i])/n