//FEbruary Lunchtime 2019 -Problem 1
//By Mohit Maroliya

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  std::cin >> t;
  while(t--)
{
  int n,k;long v,ans;
  std::cin >> n>>k>>v;
  long a[n],sum=0;
  for(int i=0;i<n;i++)
  {std::cin >> a[i];
   sum+=a[i];
  }
  //((n+k)*v-sum=number) divided by k
  ans=(((n+k)*v)-sum);
  if((ans%k==0)&&(ans>0))
  std::cout << ans/k << '\n';
  else
  std::cout << "-1" << '\n';
}
	return 0;
}
