# Enter your code here. Read input from STDIN. Print output to STDOUT
import string
T=raw_input()
T=int(T)
pi="31415926535897932384626433833"
processString=''
for i in range(0,T):
    n=raw_input()
    punct=set(string.punctuation)
    processString=''.join(ch for ch in n if ch not in punct)
    processString=processString.split(' ')
    output=''
    for ctr in range(0,len(processString)):
        output+=str(len(processString[ctr]))
    flag=1
    for k in range(0,len(output)):
        if output[k]!=pi[k]:
            flag=-1
            break
    if flag==1:
        print 'It\'s a pi song.'
    else:
        print 'It\'s not a pi song.'