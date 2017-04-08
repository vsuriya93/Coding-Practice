n=input()
sticks=raw_input()
sticks=map(int,sticks.split())
m=len(sticks)
while m>0:
	print m
	r=len(sticks)
	k=0
	val=min(sticks)
	while k<r:
		if sticks[k]==val:
			del sticks[k]
			r-=1
		else:
			k+=1
	m=len(sticks)