// THIS IS THE PROBLEM OF DEC COOK-OFF 18

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    int p[n],d[n];
    for(int i=0;i<n;i++)
    {
      std::cin >> d[i] >> p[i];
    }
    int q;
    std::cin >> q;
    int dead,req,sum;
    for(int i=0;i<q;i++)
    {
      std::cin >> dead >> req;
      if(dead<d[0])
      {
        std::cout << "Go Sleep" << '\n';
      }
      else
     {
       sum=0;
      for(int j=0;j<n;j++)
      {
       if(dead >= d[j])
        {
          sum+=p[j];  
          //std::cout << "sum=" << sum << '\n';
        }
      }
        //std::cout << "sum11=" << sum << '\n';
      if(sum>=req)
       {
        std::cout << "Go Camp" << '\n';
       }
      else if(sum<req)
       {
        std::cout << "Go Sleep" << '\n';

       }
     }
   }
 }
  return 0;
}
