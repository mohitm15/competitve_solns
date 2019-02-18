//February Cook-Off 2019 :Problem 2
//By  Mohit Maroliya

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
   int t;
   std::cin >> t;
   while(t--)
   {
      long n,cnt=0;
      std::cin >> n;
      long a[n];
      for(int i=0;i<n;i++)
      {
        std::cin >> a[i];
      }
      sort(a,a+n);
      for(int i=0;i<n;i++)
      {
        if(a[0]!=0)
        {
          cnt=0;
          break;
        }
        else if((a[i]==0)||(a[i]<=cnt))
        {
          cnt++;
          //std::cout << "CNT-" << cnt <<'\n';
        }
      }
      std::cout << cnt << '\n';
   }
  return 0;
}
