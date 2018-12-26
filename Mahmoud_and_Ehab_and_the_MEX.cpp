//contest: Codeforces Round #435 (Div. 2), problem: (A) Mahmoud and Ehab and the MEX, Accepted, #
 #include<bits/stdc++.h>
using namespace std;
int main(){
int n;
int k;
int x;
cin>>n>>k;
int ans=k;
for(int i=0;i<n;i++)
{
cin>>x;
if(x<k){
ans--;
}
else if(x==k)
{
ans++;
}
}
cout<<ans;
return 0;
}
