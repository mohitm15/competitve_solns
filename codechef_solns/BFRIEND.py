# Codechef January Lunchtime 2020 : Problem 2
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
import math
for i in range(int(input())):
	n,a,b,c = map(int,input().split())
	l = list(map(int,input().split()))
	l.sort
	t = 0
	top = l[n-1]
	bot = l[0]
	if a<=b and b<=bot:
		t = bot-a +bot-b +c
	elif b<=a and a<=bot:
		t = bot-a +bot-b+c
	elif a<=b and a>=top:
		t = a-top+b-top+c
	elif b<=a and b>=top:
		t = a-top+b-top+c
	elif a>=top and (top>=b and b>=bot):
		t = a-b+c
	elif b>=top and (top>=a and a>=bot):
		t = b-a+c
	elif a<=bot and (bot<=b and b<=top):
		t = b-a+c
	elif b<=bot and (bot<=a and a<=top):
		t = a-b+c
	elif a>=top and b<=bot:
		t = a -b+c
	elif b>=top and a<=bot:
		t = b-a+c
	elif (bot<=a and a<=top) and (bot<=b and b<=top):
		if b!=a:
			t = abs(b-a)+c
		else:
			#ab index wala case
			mn = top-bot
			for i in range(0,n):
				mn = min(mn,abs(l[i]-b))
			t = 2*mn+c				
	elif a==b:
		if a<=bot:
			t = 2*(bot-a)+c
		elif a>=top:
			t = 2*(top-a)+c
	print(t)
