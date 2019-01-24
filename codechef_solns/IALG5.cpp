//By Mohit Maroliya
// Innovacion 2019 : Algorithmis --Problem 1

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,k,cnt=0;
  int r;
  std::cin >> n>>k>>r;
  for(int i=1;i<=n;i++)
  {
    k-=(i*r);
    //std::cout << "k=" <<k<< '\n';
    if(k<0)
    break;
    cnt++;
    if(k<(i*r))
      break;
    //std::cout << cnt << '\n';
  }
      //std::cout << cnt << '\n';
  std::cout << n-cnt << '\n';
  return 0;
}
