//DAY 03

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
  if(n % 2 !=0)
  std::cout << "Weird" << '\n';
  else
  {
    if(n<=5)
    std::cout << "Not Weird" << '\n';
    else if(n<=20)
    std::cout << "Weird" << '\n';
    else if(n>=20)
    std::cout << "Not Weird" << '\n';
  }
    return 0;
}
