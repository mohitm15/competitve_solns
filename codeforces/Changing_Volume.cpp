
//By mmhaxor, contest: Codeforces Round #601 (Div. 2), problem: (A) Changing Volume, Accepted, #

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
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
 
using namespace std;
 
int main()
{
	int tt;
	cin>>tt;
	while(tt--)	
	{
		//cout<<"MOhit";
		int a,b;
		cin>>a>>b;
		int cnt=0;
		int diff = abs(a-b);
	//	cout<<"asda  "<<endl;
		cnt = diff/5;
		//cout<<"cnt  = "<<cnt<<endl;
		diff = diff%5;
		//cout<<"diff%5 = "<<diff<<endl;
		if(cnt==0)
		    {
		        if (diff == 4 || diff==3)
		        {
			        cnt=2;;
		        }
		        if(diff ==1 || diff ==2)
		        {
		            cnt=1;
		        }
		    }
		else
		{
    		if(diff==4  || diff==3)
    		{
    			cnt+=2;
    		}
    		else if( diff==1 || diff==2)
    		{
    			cnt+=1;
    		}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
