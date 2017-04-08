# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
text=raw_input()
newText=''.join(text.split())
dim=len(newText)
r=math.sqrt(dim)
if r==int(r):
    r=int(r)
    c=r
else:
    r=int(r)
    c=r+1
if r*c <dim:
    r+=1
matrix=[['' for x in range(0,c)] for y in range(0,r)]
count=0
for i in range(0,r):
    for j in range(0,c):
        if count<dim:
            matrix[i][j]=newText[count]
            count+=1
output=''          
for i in range(0,c):
    output=''
    for j in range(0,r):
        output+=matrix[j][i]
    print output,
    #print
