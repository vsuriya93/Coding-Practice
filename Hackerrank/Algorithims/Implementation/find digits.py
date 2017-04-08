# Enter your code here. Read input from STDIN. Print output to STDOUT
testCase=raw_input()
testCase=int(testCase)
for i in range(0,testCase):
    str_n=raw_input()
    n=int(str_n)
    count=0
    for ctr in range(0,len(str_n)):
        value=int(str_n[ctr])
        if value!=0 and n%value==0:
            count+=1 
    print count