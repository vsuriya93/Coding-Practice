# Enter your code here. Read input from STDIN. Print output to STDOUT
returnDate=raw_input()
returnDate=map(int,returnDate.split(' '))
actualDate=raw_input()
dueDate=map(int,actualDate.split(' '))
#print returnDate,dueDate
if (returnDate[2]-dueDate[2])>0:
    fine=10000
elif (returnDate[2]-dueDate[2])==0:
    if (returnDate[1]-dueDate[1])>0:
        fine=(returnDate[1]-dueDate[1])*500
    elif (returnDate[1]-dueDate[1])==0:
        if returnDate[0]>=dueDate[0]:
            fine=(returnDate[0]-dueDate[0])*15
        else:
            fine=0
    else:
        fine=0
else:
    fine=0
print fine