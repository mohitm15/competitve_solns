// Technocup Elimination Round #4, Problem (A)
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans;
        cin>>n;
        if(n<=9 && n>0)
        ans=n;
        else
        {
            ans = 9;
            int num =1,i=1;
            while(num<n)
            {
                //cout<<num<<endl;
                
                num = pow(10,i)+num;
                int numcpy=num;
                for(int j=1;j<=9;j++)
                {
                    if(numcpy>n)
                    break;
                    else
                    {
                        //cout<<numcpy<<" -> ";
                        numcpy=numcpy+num;
                        ans+=1;
                    }    
                }
                i++;
            }
            //cout<<num<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
