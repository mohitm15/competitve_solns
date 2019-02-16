//Day 7

#include <bits/stdc++.h>
//#define f(i,n) for(int i=0;i<n;i++);
using namespace std;



int main()
{
   int n;
   std::cin >> n;
   std::vector<int> v(n);
   for(int i=0;i<n;i++)
   std::cin >> v[i];
   reverse(v.begin(),v.end());
   for(int i=0;i<n;i++)
   std::cout <<  v[i] << " ";
   std::cout << '\n';
    return 0;
}
