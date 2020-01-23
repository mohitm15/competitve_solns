# contest: Codeforces Round #615 (Div. 3), problem: (C) Product of Three Numbers, Accepted, #
tt =int(input())
for i in range(tt):
	n=int(input())
	l=[]
	a=2
	while len(l)<2 and i*i<n:
		if n%a==0:
			l.append(a)
			n//=a
		a+=1
	if len(l)==2 and n not in l:
		print('YES')
		print(*l,n)
	else:
		print('NO')
