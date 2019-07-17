# June Lunchtime 2019: Problem 1
# By Mohit Maroliya

t=int(input())
while t>0:
    x=list(map(int, input().split()))
    cnt=0
    tota=x[0]+x[1]
    if(x[0]==0 and x[1]==0):
        print("Chef")
    else:
        cnt=tota//x[2]
    if cnt%2==0:
        print("Chef")
    else:
        print("Paja")
    t-=1
