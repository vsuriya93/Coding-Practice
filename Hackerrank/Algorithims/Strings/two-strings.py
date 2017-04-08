# Enter your code here. Read input from STDIN. Print output to STDOUT
temp=raw_input()
temp=int(temp)

for count in xrange(temp):
    first=raw_input()
    second=raw_input()
    if set(first) & set(second):
        print "YES"
    else:
        print "NO"
    
