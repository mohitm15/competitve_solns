# contest: Codeforces Round #632 (Div. 2), problem: (C) Eugene and an array, Accepted, #, Copy
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
 
n = int(input())
arr = [int(x) for x in input().split()]
arr.insert(0 , 0)
mp = {0 : 0}
sol = (n*(n+1))//2
acum = 0
index = -1
for i in range(1 , n+1):
    acum += arr[i]
    if acum in mp:
        index = max(index , mp[acum])
    mp[acum] = i
    sol -= index+1
    # print("acum = ",acum)
    # print("inc = ",index)
    # print("map", mp)
    # print("sol = ",sol)
    # print("------------------")
print(sol)
