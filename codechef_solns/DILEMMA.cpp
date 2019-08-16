// code chef August Long Challenge : Problem 3
// Mohit MAroliya

#include<bits/stdc++.h>
using namespace std;
#define next cout<<endl;
#define ull unsigned long long int
#define f(i,n) for(int i=0;i<n;i++)
int main() 
{
int t;cin>>t;
while(t--)
{ 
    string s;cin>>s;int sum=0;
	f(i,s.length()){if(s[i]=='1') sum++;}
	if(sum%2==0) cout<<"LOSE\n";
	else cout<<"WIN\n";
}
return 0; 
} 
