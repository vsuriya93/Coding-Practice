# Enter your code here. Read input from STDIN. Print output to STDOUT
n=input()
matrix=[]
for i in xrange(0,n):
    val=raw_input()
    val=map(int,list(val))
    matrix.append(val)
for i in xrange(0,n):
    output=''
    for j in xrange(0,n):
        val=matrix[i][j]
        if (i>0 and i<n-1) and (j>0 and j<n-1):
            if val> max(matrix[i-1][j],matrix[i+1][j],matrix[i][j-1],matrix[i][j+1]):
                #print 'X',
                output+='X'
            else:
                #print val,
                output+=str(val)
        else:
            #print val,
            output+=str(val)
    print output