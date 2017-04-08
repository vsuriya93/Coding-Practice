# Enter your code here. Read input from STDIN. Print output to STDOUT
p=input()
q=input()
isFound=False
flag=0
for i in range(p,q+1):
    sqr=str(i*i)
    length=len(sqr)
    toCheck=True
    flag=0
    if length%2==0:
        left=sqr[0:length/2]
        right=sqr[length/2:]
        if left!='' and right!='':
            value=int(left)+int(right)
        elif left!='' and right=='':
            value=int(left)
            if value==0:
                toCheck=False
        elif left=='' and right!='':
            value=int(right)
            if value==0:
                toCheck=False
        if toCheck==True and value==i:
            isFound=True
            print i,
    elif length%2!=0:
        d=length//2
        left=sqr[0:d]
        right=sqr[d:]     
        #print left,right,d,i
        if length==1:
            value=int(right)
        elif left!='' and right!='':
             value=int(left)+int(right)
        elif left!='' and right=='':
            value=int(left)
            if value==0:
                toCheck=False
        elif left=='' and right!='':
            value=int(right)
            if value==0:
                toCheck=False
        if toCheck==True and value==i:
            isFound=True
            flag=1
            print i,
            continue
        if flag==0:
            d=d+1
            left=sqr[0:d]
            right=sqr[d:]        
            #print i,d,left,right
            if length==1:
                value=int(left)
            elif left!='' and right!='':
                 value=int(left)+int(right)
                 if int(left)==0 or int(right)==0:
                    toCheck=False
            elif left!='' and right=='':
                value=int(left)
                if value==0:
                    toCheck=False
            elif left=='' and right!='':
                value=int(right)
                if value==0:
                    toCheck=False
            if toCheck==True and value==i:
                isFound=True
                flag=0
                print i,
                continue
            
if isFound==False:
    print 'INVALID RANGE'