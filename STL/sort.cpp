#include<iostream>
#include<algorithm>
using namespace std;
void display(int a[])
{
  for(int i=0;i<8;i++)
  {
    std::cout << a[i] << " ";
  }
}
int main()
{
  int a[8]={3,4,6,2,1,9,8,7};
  std::cout << "before" << '\n';
  display(a);
  sort(a,a+8);
  std::cout << "after" << '\n';
  display(a);
  return 0;
}
