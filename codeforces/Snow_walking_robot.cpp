
// contest: Codeforces Round #605 (Div. 3), problem: (B) Snow Walking Robot, Happy New Year!, #
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;++i)
#define rf(j,n) for(int j=n;j>0;j--)
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
 
int mini(int a,int b)
{
	int ans;
	ans = a>=b?b:a;
	return ans;
}
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		string s;
		cin>>s;
		int l=0,r=0,u=0,d=0;
		for(auto c:s)
		{
			if(c=='L')
			l++;
			else if(c=='R')
			r++;
			else if(c=='D')
			d++;
			else if(c=='U')
			u++;
		}
		int ud = mini(u,d);
		int lr = mini(l,r);
		string p="";
		if(ud==0 && lr==0)
			{
				cout<<0<<endl;
			}
		else if(ud==0)
			{
				cout<<2<<endl;
				cout<<"LR"<<endl;
			}
		else if(lr==0)
			{
				cout<<2<<endl;
				cout<<"UD"<<endl;
			}
		else
		{
			/* code */
			f0(i,lr)
			p+="L";
			f0(i,ud)
			p+="U";
			f0(i,lr)
			p+="R";
			f0(i,ud)
			p+="D";
			cout<<2*(lr+ud)<<endl;
			cout<<p<<endl;
		}
	}
	return 0;
}
