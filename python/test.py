# ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
# ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
# ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
# ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
# ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
# ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
# ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
# ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
# ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
# ░░░░░░█░░░░░░  ░░░░░  ░░░█░░░░░
# ░░░░░░█░░░░░░ ░ ░░░ ░ ░░░█░░░░░
# ░░░░░░▀░░░░░░ ░░ ░ ░░ ░░░▀░░░░░
# ░░░░░░░░░░░░░ ░░░ ░░░ ░░░░░░░░░

MOD =  1000000007
mod = 10009
#import time
#import heapq
import math
#import string
#import bisect
import collections
#import itertools
 
def primeseive(n):
    prime = [True for i in range(n+1)]
    p=2
    while p*p<=n:
        if prime[p]==True:
            for i in range(p*p,n+1,p):
                prime[i]=False
        p+=1
    ans = [i for i in range(2,n+1) if prime[i]]
    print(ans)

def checkprime(n):
    if n == 2: return True
    if n % 2 == 0 or n <= 1: return False
    sqr = int(math.sqrt(n)) + 1
    for d in range(3, sqr, 2):
        if n % d == 0: return False
    return True

def primeFactors(n): 
    prime = set()
    while n % 2 == 0: 
        prime.add(2)
        n = n//2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            prime.add(i)
            n = n//i 
    if n > 2: 
        prime.add(n)
    return list(prime)

def sort_dict(key_value):
    return sorted(key_value.items(), key = lambda kv:(kv[1], kv[0]))

def xymodm(x,y,m):
    res = 1
    x=x%m
    if x==0:
        return 0
    while y>0:
        if y&1:
            res =(res*x)%m
        y = y//2
        x = (x*x)%m
    return res

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def subarray(a):
    sub = [[]]
    for item in sorted(a):
        sub += [ prevsub + [item] for prevsub in sub]
    return sorted(sub)
#-------------------------------------------------
def swap(a,b):
    temp =a
    a = b
    b =temp
    return a,b

def solve(mat):
    R=4
    C=5
    hist = [[0 for i in range(C + 1)] 
        for i in range(R + 1)] 

	# Step 1: Fill the auxiliary array hist[][] 
    for i in range(0, C, 1): 
        
        # First row in hist[][] is copy of 
        # first row in mat[][] 
        hist[0][i] = mat[0][i] 

        # Fill remaining rows of hist[][] 
        for j in range(1, R, 1): 
            if ((mat[j][i] == 0)): 
                hist[j][i] = 0
            else: 
                hist[j][i] = hist[j - 1][i] + 1

	# Step 2: Sort rows of hist[][] in 
	# non-increasing order
    for i in range(R):
        print(hist[i]) 
    for i in range(0, R, 1): 
        count = [0 for i in range(R + 1)] 

        # counting occurrence 
        for j in range(0, C, 1): 
            count[hist[i][j]] += 1

        # Traverse the count array from 
        # right side 
        col_no = 0
        j = R 
        while(j >= 0): 
            if (count[j] > 0): 
                for k in range(0, count[j], 1): 
                    hist[i][col_no] = j 
                    col_no += 1

            j -= 1
			
	# Step 3: Traverse the sorted hist[][] 
	# to find maximum area 
    for i in range(R):
        print(hist[i])
    max_area = 0
    for i in range(0, R, 1): 
        for j in range(0, C, 1): 
            
            # Since values are in decreasing order, 
            # The area ending with cell (i, j) can 
            # be obtained by multiplying column number 
            # with value of hist[i][j] 
            curr_area = (j + 1) * hist[i][j] 
            if (curr_area > max_area): 
                max_area = curr_area 

    print("ans = ",max_area)



# cook your dish here
def solve(n,a):
    if a.count(a[0]) == n: return -1
    ans = 0
    index = [i for i in range(0)]
    i =1
    while len(a)>1:
        if a[i]>a[i-1]:
            a[i]+=1
            ans = index[i]
            a.remove(a[i-1])
            
        elif a[i]>a[i+1]:
            a[i]+=1
            ans = index[i]
            a.remove(a[i+1])

    

noOfTestCases = int(input())    
for i in range(noOfTestCases):
    #l,r = map(int,input().split())
    #a = list(map(int,input().split()))
    n = int(input())
    a = list(map(int,input().split()))
    #s = input()
    ans = solve(n,a)
    print(ans)