# contest: Codeforces Round #615 (Div. 3), problem: (B) Collecting Packages, Accepted, #
for i in range(int(input())):
    n = int(input())
    l = []
    for j in range(n):
        x,y =map(int,input().split())
        ele = [x,y]
        l.append(ele)
    #print(l)
    l.sort()
    #print(l)
    s = ""
    st =0
    en = 0
    flag = True
    for k in range(n):
        if ((l[k][0]-st)<0) or ((l[k][1]-en)<0):
            flag =False
            break
        else:    
            s=s+("R"*(l[k][0]-st)+"U"*(l[k][1]-en))
            st = l[k][0]
            en = l[k][1]
    if flag:
        print("YES")
        print(s)
    else:
        print("NO")
