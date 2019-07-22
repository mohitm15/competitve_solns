# Codechef July Cook-Off 2019 : Problem 1
# By Mohit Maroliya

# cook your dish here
t=int(input())
while t>0:
    n=int(input())
    s1=int(input())
    res1 = [int(x) for x in str(s1)]
    s2=int(input())
    res2 = [int(x) for x in str(s2)]
    num1=res1.count(1)
    num2=res2.count(1)
    #print("num1= ",num1)
    #print("num2= ",num2)
    if num1==num2:
        print("YES")
    else:
        print("NO")    
    t-=1
