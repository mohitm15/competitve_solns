# Codechef July Cook-Off 2019 : Problem 2
# By Mohit Maroliya 
# Time limit exceeded

t=int(input())
while t>0:
    x=y=cnt=0
    p=1
    n=int(input())
    while x<=n:
        if p*p>y:
            x=p
            y+=(p*p)
            cnt+=1
        else:
            p+=1
    print(cnt)
    t-=1
