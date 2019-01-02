#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll num;
  cin>>num;
  vector<ll>v;
  for(ll i=0;i<num;i++){
      ll b = 0;
      cin>>b;
      v.push_back(b);
      
  }
  
  sort(v.begin(),v.end());
  ll max1=0;
  
  for(ll i=0;i<num;i++)
  {
      max1 = max(v[i]*(num-i),max1);
  }
  cout<<max1;
  return 0;
  }
