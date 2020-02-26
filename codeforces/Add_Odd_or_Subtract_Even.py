# Contest: Codeforces Round #624 (Div. 3), problem: (A) Add Odd or Subtract Even, Accepted, #, Copy
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
    a,b = map(int,input().split())
    if a==b:
        print(0)
    diff = abs(a-b)
    if a<b:
        if diff%2==0:
            print(2)   #do odd ka sum
        elif diff%2==1:
            print(1)   # ek odd = b-a add karna hai a mei
    elif a>b:
        if diff%2==0:
            print(1)   # ek even subtract karna hai a se
        if diff%2==1:
            print(2)  # add +1 to a and then subtract a+1-b (even)
