#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n,score=0;
    std::cin >> n;
    char ans[n],res[n];
    f(i,n)
    std::cin >> ans[i];
    f(i,n)
    std::cin >> res[i];
    for(i,n)
    {
      if( ans[i] == res[i] )
        score=+1;
      else if(res[i] == 'N')
        score+=0;
      else
        i++;
    }
    std::cout << "score= " <<score<< '\n';
  }
  return 0;
}
