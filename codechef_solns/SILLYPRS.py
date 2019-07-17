# June Lunchtime 2019: Problem 2
# By Mohit Maroliya

t=int(input())
while t>0:
    n=int(input())
    Aodd=Bodd=sumA=sumB=0
    a = list(map(int,input().strip().split()))[:n]
    b = list(map(int,input().strip().split()))[:n]
    for i in a:
        sumA+=i
        if i%2==1:
            Aodd+=1
    for i in b:
        sumB+=i
        if i%2==1:
            Bodd+=1
    ans=(sumA+sumB-abs(Aodd-Bodd))//2
    print(ans)
    t-=1
