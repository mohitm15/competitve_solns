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
    int n,k,m;
    std::cin >> n;
    int a[n];
    f(i,n)
    std::cin >> a[i];
    std::cin >> k;
    m=a[k-1];
    sort(a,a+n);
    // f(i,n)
    // std::cout << a[i] << "--";
    // std::cout << '\n';
    f(i,n)
    {
      if(m==a[i])
      std::cout << i+1 << '\n';
    }
  }
  return 0;
}
