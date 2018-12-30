//contest: Codeforces Round #482 (Div. 2), problem: (A) Pizza, Pizza, Pizza!!!, Happy New Year!, #
/USE PYTHON 3.0 COMPILER


n = int(input())
if n == 0:
    print(0)
else:
    if n % 2 == 0:
        print(n+1) 
    else:
        print((n+1)//2)
