# Enter your code here. Read input from STDIN. Print output to STDOUT
h=input()
m=input()
hr=['one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve']
minute=['one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen','twenty','twenty one','twenty two','twenty three','twenty four','twenty five','twenty six','twenty seven','twenty eight','twenty nine']
output=''
if m==30:
    output='half'+' past '+hr[h-1]
elif m==0:
    output=hr[h-1]+' o\' clock' 
elif m<30:
    if m==15:
        output='quarter' + ' past ' + hr[h-1]
    else:
        output=minute[m-1]+' minutes past '+hr[h-1]
elif m>30:
    if m==45:
        output='quarter' + ' to ' + hr[h]
    else:
        output=minute[60-m-1]+' minutes to '+hr[h]
print output