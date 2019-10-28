 
/**
 *    author:  mohitm
 *    created: 28.10.2019 15:16:26       
**/


//Codechef October Lunchtime 2019: Problem 2

#include <iostream>
#include<vector>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
    cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--)
	{
	    
	    ll n;ll c1=0;ll c2=0;ll k;
	    cin>>n>>k;
	    vector<ll> a(n);
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i;j<n;j++)
	        {
	            if(a[i]>a[j])
	            c1++;
	        }
	    }
	    //c1*=k;
	    ll ans=0;
	    for(int i=0;i<n;i++)
	    {
	        c2=0;
	        for(int j=0;j<n;j++)
	        {
	            if(a[i]>a[j])
	            c2++;
	        }
	        ans=((k-1)*k/2)*c2+ans;
	    }
	    
	    cout<<c1*k+ans<<endl;
	}
	return 0;
}
