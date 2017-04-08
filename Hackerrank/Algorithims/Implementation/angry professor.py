# Enter your code here. Read input from STDIN. Print output to STDOUT
testCase=raw_input()
testCase=int(testCase)
for k in range(0,testCase):
    S=raw_input()
    T=raw_input()
    s=map(int,S.split(' '))
    t=map(int,T.split(' '))
    count=0
    for i in range (0,s[0]):
        if t[i]<=0:
            count+=1
    if count>=s[1]:
        print 'NO'
    else:
        print 'YES'