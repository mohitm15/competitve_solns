// Successful Submission:International Coding League 2019 -Problem 1

//By Mohit Maroliya

#include<iostream>
using namespace std;

int main()
{
  int n,m;
  int a[31]={961,900,841,784,729,676,625,576,529,484,441,400,361,324,289,256,225,196,169,144,121,100,81,64,49,36,25,16,9,4,1};
  std::cin >> n;
  m=n;
  int cnt=1;
  for(int i=0;i<30;i++)
  {
    if(m>a[i])
    {
      m=m-a[i];
      cnt++;
      //std::cout << "yo" << '\n';
    }
    else if(n==a[i])
    {
       cnt=1;
      break;
    }
    else if(m==a[i])
    {
      // cnt++;
      break;
    }
  }
  //if(n==0)
  std::cout << cnt << '\n';
  return 0;
}
