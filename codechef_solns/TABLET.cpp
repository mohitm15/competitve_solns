//February Cook Off 2019 :Problem 2

//By Mohit Maroliya


#include<iostream>
#include<map>
using namespace std;

int main()
{
   int t;
   std::cin >> t;
   while(t--)
   {
     long n,x;
     std::cin >> n>>x;
     long w[n],h[n],p[n];
     for(int i=0;i<n;i++)
     std::cin >> w[i]>>h[i]>>p[i];
     long max=0,cnt=0;
     for(int i=0;i<n;i++)
     {
       if(p[i]<=x)
       {
         if(max<(h[i]*w[i]))
         max=h[i]*w[i];
       }
       else
       cnt++;
     }
     if(cnt==n)
     std::cout << "no tablet" << '\n';
     else
     std::cout << max << '\n';
   }
  return 0;
}
