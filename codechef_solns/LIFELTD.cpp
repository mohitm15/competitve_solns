#include <iostream>
using namespace std;

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    char ch[3][3];
    for(int i=0;i<3;i++)
     {
       for(int j=0;j<3;j++)
         std::cin >> ch[i][j];
     }
     int cnt=0;
    for(int i=0;i<2;i++)
    {
      for(int j=0;j<2;j++)
      {
        if(ch[i][j]=='l')
        {
          if(ch[i+1][j]=='l' && ch[i+1][j+1]=='l')
         {
           cnt+=1;
         }

        }
      }
    }
    if(cnt>0)
    std::cout << "yes" << '\n';
    else
    std::cout << "no" << '\n';
  }
  return 0;
}
