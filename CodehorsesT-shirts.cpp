//SOLN BY MOHIT

#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

long long int n,acc,sol;
string inp;
map<string,int> sizes;

int main()
{

    std::cin >> n;

    for(int i=0;i<n;i++)
    {
        cin>>inp;
        sizes[inp]++;
        acc++;
    }

    while(n--)
    {
        cin>>inp;
            sizes[inp]--;
            acc--;
    }

for(auto u : sizes)
   sol+=abs(u.second);

    std::cout << sol/2 << '\n';
  return 0;
}
