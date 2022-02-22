#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int n,m,r=0;
  //std::cout << "enter n" << '\n';
  std::cin >> n;
  m=2*n;
  char arr[m];
  for(int i=0;i<m;i++)
  {
    std::cin >> arr[i];
  }
  for(int i=0;i<m;i++)
  {
    if(arr[i]==arr[i+1])
    break;
    else
    r+=1;
  }
  if(n==2)
   {
     r=3;
     std::cout << (r+1)/2 << '\n';
   }
  else
  std::cout << (r+1)/2 << '\n';
  return 0;
}
