def solve(n,a):
    return n



noOfTestCases = int(input())    
for t in range(noOfTestCases):
    n = int(input())
    #n,m= map(int,input().split())
    #s1 = input()
    a = list(map(int,input().split()))
    #b = list(map(int,input().split()))
    ans = solve(n,a)
    print(ans)
    #print(*ans,sep=" ")