// contest: Codeforces Round #599 (Div. 2), problem: (B2) Character Swap (Hard Version), Happy New Year!, #
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
 
using namespace std;
 
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░▀░░░░░░░░░░░░░░░░░░▀░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
 
 
int maxi(int a,int b)
{
	int ans = a>=b?ans=a:ans=b;
	return ans;
}
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		vector<pair<int,int>>ans;
		f0(i,n)
		{
			if(a[i]!=b[i])
			{
				for(int j=i+1;j<n;j++)
				{	
					if(a[i]==a[j])
					{
    					swap(a[j],b[i]);
    					ans.push_back({j+1,i+1});
    					break;
					}
					if(a[i]==b[j])
					{
    					swap(a[j],b[j]);
    					swap(b[i],a[j]);
    					ans.push_back({j+1,j+1});
    					ans.push_back({j+1,i+1});
    					break;
					}	
				}
			}
		}
		if(a!=b)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		f0(i,ans.size())
		cout<<ans[i].first<<" "<<ans[i].second<<endl; 
	}
	return 0;
}
