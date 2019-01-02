#include<iostream>
#include<algorithm>
#define f(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    long long int g,n;
    std::cin >> g;
    while(g--)
    {
      int l,q,ans=0;
      std::cin >> l >> n >>q;
      if(n%2!=0)
      {
        if(l==1 && q==1)
        {
          ans=(n-1)/2;
          std::cout << ans << '\n';
        }
        else if(l==1 && q==2)
                {
                  ans=(n+1)/2;
                  std::cout << ans << '\n';
                }
                else if(l==2 && q==1)
                        {
                          ans=(n+1)/2;
                          std::cout << ans << '\n';
                        }
                        else if(l==2 && q==2)
                                {
                                  ans=(n-1)/2;
                                  std::cout << ans << '\n';
                                }
      }
else
{
  ans=n/2;
  std::cout << ans << '\n';
}
    }
  }
  return 0;
}
