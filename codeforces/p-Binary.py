# contest: Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2), problem: (C) p-binary, Accepted, #, Copy
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
 
def solve(n,p):
	#at = n-k*p
	if p==0:
		b = bin(n)
		return b.count("1")
	else:
		k = 0
		b = bin(n-p)
		b = b[2:]
		cnt = b.count("1")
		for k in range(1,32):
			ib = (n-k*p) 
			b = bin(ib)
			cnt  = b.count("1")
			#print("b=",b ,"and  k = ",k)
			if cnt<=k and ib>0:
				if (ib<=2 and cnt < k):
					continue
				return k
		return -1
 
n,p = map(int,input().split())
ans  = solve(n,p)
print(ans)
