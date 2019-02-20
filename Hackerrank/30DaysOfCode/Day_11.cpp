//DAY 11

#include <bits/stdc++.h>
// #define f(i,n) for(int i=0;i<n;i++);
// #define ff(i,n) for(int i=1;i<n;i++);
using namespace std;



int main()
{
int a[6][6],max=-100,sum=0;
for(int i=0;i<6;i++)
  for(int j=0;j<6;j++)
  std::cin >> a[i][j];

for(int i=1;i<5;i++)
{
  for(int j=1;j<5;j++)
  {
    sum=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
    if(sum>=max)
    max=sum;
    //std::cout << "sum=" <<sum<< '\n';
  }
}
    std::cout << max << '\n';
    return 0;
}
