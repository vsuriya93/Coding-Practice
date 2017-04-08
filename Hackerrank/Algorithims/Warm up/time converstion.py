# Enter your code here. Read input from STDIN. Print output to STDOUT
time=raw_input()
component=time.split(':')
minutes=component[1]
seconds=component[2][:2]
if component[2][2]=="P":
    hr=component[0]
    if hr=='12':
        pass
    else:
        hr=int(hr)+12
        
else:
    hr=component[0]
    seconds=component[2][:2]
    if hr=='12' :
        hr='00'
output=str(hr)+':'+minutes+':'+seconds
print output