# Enter your code here. Read input from STDIN. Print output to STDOUT
test=input()
funny=False
for i in range(test):
    funny=False
    s=raw_input()
    r=s[::-1]
    for j in range(1,len(s)):
        if abs(ord(s[j])-ord(s[j-1]))!=abs(ord(r[j])-ord(r[j-1])):
            funny=False
            break
        else:
            funny=True
    if funny:
        print "Funny"
    else:
        print "Not Funny"