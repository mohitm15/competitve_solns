#include<iostream>
using namespace std;

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int a,b;
    char sum;
      std::cin >> a >> b;
    if(a>b)
    std::cout << ">" << '\n';
    else if(a<b)
    std::cout << "<" << '\n';
    else
    std::cout << "=" << '\n';
  }
  return 0;
}
