// June Cook-Off 2019: Problem 2
// BY Mohit Maroliya

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ull unsigned long long int
#define mod 100000007

int main() {
    
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,ans=0,maxi1=0,maxi2=0,maxindex;cin>>n;cin>>m;
		int d[n],v[n];
		f(i,n)cin>>d[i]>>v[i];
		f(i,n)
		{if(maxi1<=v[i]){maxindex=i;maxi1=v[i];}}
		f(i,n)
		{if(d[i]!=d[maxindex]){if(maxi2<=v[i]){maxi2=v[i];}}}
		ans=maxi1+maxi2;cout<<ans<<endl;
	}
	return 0;
}
