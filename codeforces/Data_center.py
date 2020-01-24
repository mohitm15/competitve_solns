# contest: 2019-2020 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Teams Preferred), problem: (F) Data Center, Accepted, #, Copy
import math
# ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 
# ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
# ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
# ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
# ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
# ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
# ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
# ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
# ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
# ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
# ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
# ░░░░░░▀░░░░░░░░░░░░░░░░░░▀░░░░░
# ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
ar = int(input())
rt = int(math.sqrt(ar))
sq = rt**2
if sq == ar:
	print(4*rt)
else:
	diff = ar-1
	l=ar
	b=1
	for i in range(2,rt+1):
		if ar%i==0:
			if abs(i-(ar//i))<diff:
				diff = abs(i-(ar//i))
				l = (ar/i)
				b = i
	print(2*(int(l)+int(b)))
