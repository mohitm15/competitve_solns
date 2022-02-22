#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  int n,m,res=0;
  std::cin >> n;
  int a[n],b[n];
  for(int i=0;i<n;i++)
  {
    std::cin >> a[i];
  }
  std::vector<int> v(a,a+n);
  for(int i=0,j=1;i<n;i++,j++)
  {
    b[i]=(count(v.begin(),v.end(),a[i]));
    // if(m>=2 && a[j]==a[j-1])
    // {
    //   res=res+1;
    // }
    //  std::cout << m << '\n';
  }
  for(int i=1;i<=n;i++)
  {
    if(a[i]==a[i-1]&&b[i]==b[i-1])
     {
       res+=1;
    }
  }
   std::cout << res << '\n';
  // if(((res+2)%4)==0)
  //  std::cout << "no of pairs" << (res/2)+1 <<'\n';
  //  else
  //     std::cout << "no of paurs" << res/2 <<'\n';
  // return 0;
}
