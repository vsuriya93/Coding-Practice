# Enter your code here. Read input from STDIN. Print output to STDOUT
test=input()
for i in range(test):
    s=raw_input()
    s=list(s)
    j=1
    count=0
    while j<len(s):
        if s[j]==s[j-1]:
            del s[j]
            count+=1
        else:
            j+=1
    print count
            