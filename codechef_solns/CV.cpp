// May LunchTime 2019 : Problem 1
//BY Mohit Maroliya

#include<bits/stdc++.h>
using namespace  std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
	int t;
	cin>>t;
	//char vow[5]={'a','e','i','o','u'};
	while(t--)
  {
		int n,ans=0;
		std::cin >> n;
		char a[n];
		f(i,n)
		std::cin >> a[i];
		for(int i=0;i<(n-1);i++)
		{
				if (((a[i+1] == 'a') || (a[i+1] == 'e') || (a[i+1] == 'i') || (a[i+1] == 'o') || (a[i+1] == 'u')) && ((a[i] != 'a') && (a[i] != 'e') && (a[i] != 'i') && (a[i] != 'o') && (a[i] != 'u')))
				ans++;
		}
		std::cout << ans << '\n';
	}
}
