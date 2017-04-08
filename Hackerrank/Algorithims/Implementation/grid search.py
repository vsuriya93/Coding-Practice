# Enter your code here. Read input from STDIN. Print output to STDOUT
T=input()
for r in xrange(0,T):
    n=raw_input()
    m,n=map(int,n.split(' '))
    matrix=[]
    for i in xrange(0,m):
        entries=list(raw_input())
        entries=map(int,entries)
        matrix.append(entries)
    grid=raw_input()
    s,t=map(int,grid.split(' '))
    grid=[]
    for i in xrange(0,s):
        entries=raw_input()
        entries=map(int,list(entries))
        grid.append(entries)
    p,q=0,0
    increment=True
    result=False
    found=None
    count=-1
    isBreak=0
    #print grid
    i,j=0,0
    pos_i,pos_j=0,0
    for i in xrange(0,m-s+1):
        for j in xrange(0,n-t+1):
            if matrix[i][j]==grid[0][0] and matrix[i+s-1][j]==grid[s-1][0] and matrix[i][j+t-1]==grid[0][t-1] and matrix[i+s-1][j+t-1]==grid[s-1][t-1]:
                x=i
                y=j
                #print i,s,j,t
                for x in xrange(i,i+s):
                    for y in xrange(j,j+t):
                        p=x-i
                        q=y-j
                        #print matrix[x][y],
                        if grid[p][q]!=matrix[x][y]:
                            found=False
                            break
                        found=True
                    if found==False:
                        break
                    #print
            if found==True:
                break;
    if found==True:
        print 'YES'
    else:
        print 'NO'
			