# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
array=raw_input()
array=map(int,array.split())
sum=0
for i in range(0,len(array)):
    sum+=array[i]
print sum