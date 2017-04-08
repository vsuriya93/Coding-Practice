string = raw_input()
 
found = False
# Write the code to find the required palindrome and then assign the variable 'found' a value of True or False

string=list(string)
dict={}
for x in string:
    if dict.has_key(x):
        dict[x]+=1
    else:
        dict[x]=1
even,odd=0,0
for key in dict:
    if dict[key]%2==0:
        even+=1
    else:
        odd+=1
if odd<2:
    found=True
else:
    found=False
if not found:
    print("NO")
else:
    print("YES")
