//contest: Hello 2018, problem: (A) Modular Exponentiation, Happy New Year!, #



#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  long int n,m,r;
  std::cin >> n;
  std::cin >> m;
  r=pow(2,n);
  std::cout << m%r << '\n';
}
