// Codechef June Cook-Off Problem -1 2019:
// BY Mohit Maroliya

#include<bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n,score=0;
    std::cin >> n;
    char ans[n],res[n];
    for(int i=0;i<n;i++)
    std::cin >> ans[i];
    for(int i=0;i<n;i++)
    std::cin >> res[i];
    for(int i=0;i<n;i++)
    {
      if( ans[i] == res[i] )
        score+=1;
      else if(res[i] == 'N')
        score+=0;
      else
        i++;
    }
    std::cout << "score= " <<score<< '\n';
  }
  return 0;
}
