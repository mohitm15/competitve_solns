// contest: Codeforces Round #611 (Div. 3), problem: (A) Minutes Before the New Year, Happy New Year!, #
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
        int h,m;
        cin>>h>>m;
        cout<<1440-(60*h)-m<<endl;
    } 
	return 0; 
} 
