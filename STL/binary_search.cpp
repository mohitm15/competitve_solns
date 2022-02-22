#include<iostream>
#include<algorithm>

using namespace std;

void display(int a[],int n)
{
  for(int i=0;i<n;i++)
   std::cout << a[i] << " ";
   std::cout << '\n';
}

int main()
{
  int a[]={12,2,4,54,22,89,72,33};
  int n=sizeof(a)/sizeof(a[0]);
  bool flag1,flag2;
  std::cout << "Before" << '\n';
  display(a,n);
  std::cout << "After" << '\n';
  sort(a,a+n);
  display(a,n);
  std::cout << "Now start binary search...." << '\n';
  flag1=binary_search(a,a+n,22);
   if(flag1==1)
   std::cout << "FOUNDED" << '\n';
  else
   std::cout << "nOT FOUNDED" << '\n';
  flag2=binary_search(a,a+n,25);
   if(flag2==1)
    std::cout << "FOUNDED" << '\n';
   else
    std::cout << "NOT FOUNDED" << '\n';

    return 0;
}
