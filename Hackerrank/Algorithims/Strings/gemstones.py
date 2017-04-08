# Enter your code here. Read input from STDIN. Print output to STDOUT
test=input()
seq=[]
for i in range(test):
    temp=raw_input()
    seq.append(temp)
count=0
output=[]
for list in seq:
    if count==0:
        output=list
        count+=1
    output=set(output).intersection(list)
print len(output)