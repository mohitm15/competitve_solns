# contest: Educational Codeforces Round 76 (Rated for Div. 2), problem: (C) Dominated Subarray, Accepted, #
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
 
for i in range(int(input())):
    n = int(input())
    if n==1:
        b=int(input()) ,print("-1")
    else:
        lis = list(map(int,input().split()))
        if(len(set(lis))==1):print("2")
        elif(len(set(lis))==n):print("-1")
        else:
            mn = n+1
            ad = [-1]*(n+1)
            for k in range(0,n):
                if ad[lis[k]]!=-1:mn = min(mn,k-ad[lis[k]]+1)
                ad[lis[k]]=k
            print(mn)
