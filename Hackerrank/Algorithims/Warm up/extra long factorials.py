# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
n=int(n)
fact=1
for i in range(0,n):
    fact*=(n-i)
print fact