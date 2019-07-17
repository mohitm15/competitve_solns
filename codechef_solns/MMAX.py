# Problem 2 : July Long Challenge 2019
# By Mohit MAroliya

def minim(a,b):
    if a<b:
        return a
    else:
        return b

t=int(input())
while t>0:
    n=int(input())
    k=int(input())
    ans=0
    if n==k:
        ans=0
    elif n>k:
        if n==(2*k):
            ans=((minim(n-k,k))*2)-1
        else:
            ans=(minim(n-k,k))*2
    else:
        if (k%n)==0:
            ans=0
        else:
            rem=k%n
            if n==(2*rem):
                ans=rem*2-1
            else:
                ans=(minim(rem,n-rem)*2)
    print(ans)
    t-=1
