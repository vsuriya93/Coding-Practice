# Enter your code here. Read input from STDIN. Print output to STDOUT
n=raw_input()
n=int(n)
s=raw_input()
k=raw_input()
k=int(k)
k=k%26
output=''
for i in range(0,n):
    if (s[i]>='a' and s[i]<='z'):
        val=ord(s[i])+k
        if (val>ord('z')):
            val=val-26
        output+=chr(val)
    elif (s[i]>='A'and s[i]<='Z'):
        val=ord(s[i])+k
        if (val>ord('Z')):
            val=val-26
        output+=chr(val)
    else:
        output+=s[i]
print output