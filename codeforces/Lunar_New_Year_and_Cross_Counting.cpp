
//Contest: Codeforces Round #536 (Div. 2), problem: (A) Lunar New Year and Cross Counting, Pretests Passed #

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	std::cin >> n;
	char a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		std::cin >> a[i][j];
	}
	int cnt=0;
	for(int i=1;i<(n-1);i++)
	{
			for(int j=1;j<(n-1);j++)
			if((a[i-1][j-1]=='X')&&(a[i-1][j+1]=='X')&&(a[i+1][j-1]=='X')&&(a[i-1][j+1]=='X')&&(a[i][j]=='X'))
			cnt+=1;
	}
	std::cout << cnt << '\n';
