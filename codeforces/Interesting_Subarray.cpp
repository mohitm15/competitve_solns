// contest: Good Bye 2019, problem: (B) Interesting Subarray, Happy New Year!, #
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
#define f0(i,n) for(long long int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
 
using namespace std;
 
 
int main() 
{	
	int t;
	cin >> t;
	while(t--)
    {
        ll n,flag0=0,st=0,en=0;
        cin>>n;
        vector<ll> a(n);
        f0(i,n)
        {
            cin>>a[i];
        }
        //sort(a.begin(),a.end());
        for(int i=0;i<(n-1);i++)
        {
            if((abs(a[i+1]-a[i]))>=2)
            {
                flag0=1;
                st=i;
                en=i+1;
                break;
            }
        }
 
        if(flag0==1)
        {
            cout<<"YES"<<endl;
            cout<<st+1<<" "<<en+1<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
	}	
	return 0;
}
