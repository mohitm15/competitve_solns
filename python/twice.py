#def solve(n,m,a):
def gcd(x,y):
    while y:
        x,y = y,x%y
    return x
    
    


import math
noOfTestCases = int(input())
for i in range(noOfTestCases):
    n = int(input())
    #n,k = map(int,input().split())
    a =list(map(int,input().split()))
    if(n>=3):
        pre = [1]*(n-1)
        pre[0] = gcd(a[0],a[1])
        suf = [1]*(n-1)
        for i in range(2,n):
            pre[i-1] = gcd(pre[i-2],a[i])
        suf[n-2] = gcd(a[n-2],a[n-1])
        for j in range(n-2,0):
            print("mpohit")
            suf[j-1] = gcd(suf[j],a[j-1])
        # if(pre[n-1] == suf[0]):
        #     ans = pre[0]
        # for i in range(0,n-1):
        #     if(pre[i] == suf[i+1]):
        print(pre)
        print(suf)
        f_e = gcd(0,suf[1])
        l_e = gcd(pre[n-3],0)
        #f_l = max(f_e,l_e)
        if(f_e>l_e):
            final_ans = f_e
            final_index = 0
        else:
            final_ans = l_e
            final_index = n-1
        for i in range(1,n-1):
            if(i==1):
                ans = gcd(a[0],suf[2])
                index = 1
                if(ans>final_ans):
                    final_ans = ans
                    final_index = index
            elif(i==n-2):
                ans = gcd(pre[n-3],a[n-1])
                index = n-2
                if(ans>final_ans):
                    final_ans = ans
                    final_index = index
            else:
                ans = gcd(pre[i-2],suf[i+1])
                index = i
                if(ans>final_ans):
                    final_ans = ans
                    final_index = index
        res = (sum(a)-a[index])//final_ans + 1
        print(res)
    else:
        if(n==1):print(1)
        elif(n==2):print(2)


    # a = [[0 for i in range(m)] for j in range(m)]
    # #print(a)
    # for i in range(n):
    #     for j in range(m):
    #         momo = int(input())
    #         a[i][j] = momo
    # print(a)
    # ans = solve(n,m,a)
    # print(ans)
