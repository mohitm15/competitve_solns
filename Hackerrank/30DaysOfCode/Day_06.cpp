//DAY 6
#include <bits/stdc++.h>
//#define f(i,n) for(int i=0;i<n;i++);
using namespace std;



int main()
{
   int t;
   std::cin >> t;
   //std::string s1;
   std::string s1;
   getline(cin,s1);
   while(t--)
   {
   std::string s;
   getline(cin,s);

   for(int i=0;i<s.size();i++)
   {
     if(i%2==0)
     std::cout << s[i];
   }
   std::cout << " ";
   for(int i=0;i<s.size();i++)
   {
     if(i%2!=0)
     std::cout << s[i];
   }
   std::cout << '\n';
   }
    return 0;
}
