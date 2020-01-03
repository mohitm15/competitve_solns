// Codechef January Challenge 2020 Division 2  ; #1
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

#define f0(i,n) for(long long int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f2(i,n) for(int i=2;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>0;j--)
#define ll long long int
#define next cout<<endl
 
using namespace std;


int max(int a,int b)
{
    int ans = (a>=b)?a:b;
    return ans;
}

int min(int a,int b)
{
    int ans = (a<=b)?a:b;
    return ans;
}
int main() 
{	
	int t;
	cin >> t;
	while(t--)
    {
        int s,w1,w2,w3,sum=0,ans=1;
        cin>>s>>w1>>w2>>w3;
        sum=w1+w2+w3;
        if(s>=sum)
        ans=1;
        else
        {
            if((w1==1) && (w2==1) && (w3==1))
            {
                if(s==1)
                ans=3;
                else if(s==2)
                ans=2;
            }
            else if((w1==1) && (w2==1) && (w3==2))
            {
                if(s==2 ||s==3)
                ans=2;
            }
            else if((w1==1) && (w2==2) && (w3==2))
            {
                if(s==2)
                ans=3;
                else if(s==3)
                ans=2;
                else if(s==4)
                ans=2;
            }
            else if((w1==1) && (w2==2) && (w3==1))
            {
                if(s==2)
                ans=3;
                else if(s==3)
                ans=2;
            }
            else if((w1==2) && (w2==1) && (w3==1))
            {
                if(s==2 || s==3)
                ans=2;
            }
            else if((w1==2) && (w2==1) && (w3==2))
            {
                if(s==2)
                ans=3;
                else if(s==3 || s==4)
                ans=2;
            }
            else if((w1==2) && (w2==2) && (w3==1))
            {
                if(s==2)
                ans=3;
                else if(s==3 || s==4)
                ans=2;
            }
            else if((w1==2) && (w2==2) && (w3==2))
            {
                if(s==5 ||s==4)
                ans=2;
                else if(s==3 || s==2)
                ans=3;

            }
        }
        cout<<ans<<endl;    
	}	
	return 0;
}
