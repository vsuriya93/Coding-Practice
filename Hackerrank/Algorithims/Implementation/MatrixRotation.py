# Enter your code here. Read input from STDIN. Print output to STDOUT

def printMatrix(matrix,m,n):
    for i in xrange(0,m):
        for j in xrange(0,n):
            print matrix[i][j],
        if i!=m-1:
            print 

userInput=raw_input()
userInput=map(int,userInput.split(' '))
m,n,r=userInput[0],userInput[1],userInput[2]
matrix=[]
for i in xrange(0,m):
    userInput=raw_input()
    user=map(int,userInput.split(' '))
    matrix.append(user)
#print r
count=0
source=0
top=n
bottom=m
value=max(m,n)/2
while source < top-1 and source < bottom -1:
	#begin
	times=r%(2*(top-source)+2*(bottom-source)-4)
	#print times,top,bottom
	while times>0:
		i=source
		j=bottom-1
		temp=matrix[j][i]
		while j>source:
			matrix[j][i]=matrix[j-1][i]
			j-=1       
		i=source
		j=source
		while j<top-1:
			matrix[i][j]=matrix[i][j+1]
			j+=1
		i=source
		j=top-1
		while i<bottom-1:
			matrix[i][j]=matrix[i+1][j]
			i+=1
		i=bottom-1
		j=top-1
		while j>source:
			matrix[i][j]=matrix[i][j-1]
			j-=1
		matrix[i][j+1]=temp
		times-=1
		#printMatrix(matrix,m,n)
		#print "\n\n\n"
	# END
	count+=1
	top-=1
	bottom-=1
	source=count
printMatrix(matrix,m,n)