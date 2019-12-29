// contest: Codeforces Round #611 (Div. 3), problem: (B) ,Candies Division, Accepted,
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░  ░░░░░  ░░░█░░░░░
// ░░░░░░█░░░░░░ ░ ░░░ ░ ░░░█░░░░░
// ░░░░░░▀░░░░░░ ░░ ░ ░░ ░░░▀░░░░░
// ░░░░░░░░░░░░░ ░░░ ░░░ ░░░░░░░░░
 
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
 
using namespace std;

int mini(int a,int b)
{
    int res = a>b?b:a;
    return res;
}
 
int main() 
{	
	int t;
	cin >> t;
	while(t--)
    {
		int n, k;
		cin >> n >> k;
		int ans = n - n % k;
		ans += mini(n % k, k / 2);
		cout<<ans<< endl;
	}	
	return 0;
}
