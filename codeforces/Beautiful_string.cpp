// contest: Codeforces Round #604 (Div. 2), problem: (A) Beautiful String, Happy New Year!, #
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
#define f2(i,n) for(int i=1;i<n;i++)
#define rf(j,n) for(int j=n-1;j>0;j--)
#define ll long long int
 
using namespace std;
 
 
int main() 
{	
	int t;
	cin >> t;
	while(t--)
    {
        int flag=0;
        string s;
        cin>>s;
        int n=s.length();
        if(s[0]=='?')
        {
            if(s[1]=='a')
            s[0]='b';
            else
            s[0]='a';
        }
        f0(i,n)
        {
            if(s[i]=='?')
            {
                s[i]='a';
                char prev = s[i-1];
                char next = s[i+1];
                while((s[i]==prev) || (s[i]==next))
                {
                    s[i]++;
                }
            }
        }
        f2(i,n)
        {
            if(s[i]==s[i-1])
            flag=1;
        }
        if(flag)
        cout<<-1<<endl;
        else
        cout<<s<<endl;
 
	}	
	return 0;
}
