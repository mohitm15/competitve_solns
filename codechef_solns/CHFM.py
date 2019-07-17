# Problem -1 : July Long Challenge 2019
# BY Mohit Maroliya

t=int(input())
while t>0:
    n=int(input())
    l=list(map(int, input().split()))
    cnt=0
    imean=sum(l)
    for i in range(0,n):
        if imean == (n*l[i]):
            print(i+1)
            break
        else:
            cnt+=1
    if cnt==n:
        print("Impossible")
    t-=1
