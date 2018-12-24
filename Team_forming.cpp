#include<iostream>
#include<algorithm>
// #define f1(i,n) for(int i=0; i<n ; i++)
// #define f2(i,n) for(int i=0; i<n ; i+2)

using namespace std;

int main()
{
  int n;
  std::cin >> n;
  int a[n];
  for(int i=0; i<n ; i++)
  {
    std::cin >> a[i];
  }
  sort(a, a+n);
  int diff=0;
  int cnt=0;
  for(int i=0; i<n ;)
  {
    diff=a[i+1]-a[i];
    cnt+=diff;
    i+=2;
  }
  std::cout << '\n';
  std::cout << cnt << '\n';
  return 0;
}
