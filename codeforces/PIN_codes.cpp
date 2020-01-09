// contest: Codeforces Round #603 (Div. 2), problem: (B) PIN Codes, Happy New Year!, #
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
	ll t;
	cin>>t;
	while(t--)
    {
		ll n;
		cin>>n;
	    string  p[n+1];
	    map<string,ll>m;
		f0(i,n)
        {
		    cin>>p[i];
		    m[p[i]]++;
		}
		ll ans=0;
		if(m.size()<n)
        {
	        f0(i,n)
            {
		        if(m[p[i]]==1)continue;
		            ans++;
		        m[p[i]]--;
        		while(m[p[i]])
                {
		    		if(p[i][0]=='9') 
                        p[i][0]='0';
					else 
                        p[i][0]++;
		        }
		        m[p[i]]++;
	        }
	    }
	    cout<<ans<<endl;
	    f0(i,n)
	        cout<<p[i]<<endl;
	}
}

// Solution 2

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
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n;
		cin>>n;
		vector<string> a(n);
		set<string> v;
		f0(i,n) 
		{
			cin>>a[i];
			v.insert(a[i]);
		}
		int prev = v.size();
			// auto it =--v.end();
			// int num = stoi(*it);
			//cout<<num<<endl;
		if(v.size()!=n)
		{
			auto it =--v.end();
			int per=0;
			for(int i=v.size();i<n;i++)
				{
					int num = stoi(*it);
					int div = pow(10,(per%5));
					if((num%(div)/div)<9)
					num=num+div;
					else if((num%(div)/div)==9)
					num=num-(div);
					per++;
					string pin = to_string(num);
					v.insert(pin);
				}
		//cout<<v.size()<<endl;
		cout<<n-prev<<endl;
		for(auto im = v.begin();im!=v.end();++im)
			cout<<*im<<endl;
		}
		else
		{
			cout<<"0"<<endl;
			f0(i,n)
			cout<<a[i]<<endl;
		}
		
	}
  return 0;
}
