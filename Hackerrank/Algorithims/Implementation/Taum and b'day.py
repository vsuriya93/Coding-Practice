# Enter your code here. Read input from STDIN. Print output to STDOUT
testCase=input()
for r in xrange(0,testCase):
    item=raw_input()
    value=raw_input()
    item=map(int,item.split(' '))
    value=map(int,value.split(' '))
    b=item[0]
    w=item[1]
    x,y,z=[i for i in value]
    cost=0
    if y==min(x,y,z):
        cost+=w*y
        if x<=z :
            cost+=b*x
        elif (y+z)<=x:
            cost+=b*(y+z)
        else:
            cost+=b*x
    elif x==min(x,y,z):
        cost+=b*x
        #print x,y,z
        if y<=z :
            cost+=w*y
        elif (x+z)<=y:
            cost+=w*(x+z)
        else:
            cost+=w*y
    elif z==min(x,y,z) and x==min(x,y):
        cost+=x*b
        if (x+z)<=y:
            cost+=w*(x+z)
        else:
            cost+=y*w
    elif z==min(x,y,z) and y==min(x,y):
        cost+=y*w
        if (y+z)<=x:
            cost+=b*(y+z)
        else:
            cost+=b*x
            
    print cost