# Enter your code here. Read input from STDIN. Print output to STDOUT
s=raw_input()
s=s.lower()
check=[0]*26
for i in s:
    val=ord(i)-97
    if val>=0 and val<26:
        check[val]+=1
    else:
        pass
pangram=True
for k in check:
    if k==0:
        pangram=False
        break
    else:
        pass
if pangram:
    print "pangram"
else:
    print "not pangram"