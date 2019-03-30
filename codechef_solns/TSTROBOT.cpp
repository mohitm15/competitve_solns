// Codechef March Lunchtime 2019: Problem 1

// By Mohit Maroliya

#include<iostream>
using namespace std;

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n,x,ans=2,c=0,min=0,max=0;
    std::cin >> n >>x;
    char ch[100];
    std::cin >> ch;
    for(int i=0;i<n;i++)
    {
      if(ch[i]=='R')
      {
        // if(ch[i-1]=='R')
        // {
        //   if(c==0)
        //   ans+=1;
        //   c+=1;
        // }
        // else if(ch[i-1]=='L')
        // c-=1;
        c+=1;
        if(c>max)
        max=c;
      }
      else if (ch[i]=='L')
      {
        // if(ch[i-1]=='L')
        // {
        //   if(c==0)
        //   ans+=1;
        //   c+=1;
        // }
        // else if(ch[i-1]=='R')
        // {
        //   c-=1;
        // }
        c-=1;
        if(c<min)
        min=c;
      }
    }
    //std::cout << "max=" << max<<'\n';
    //std::cout << "min=" << min<<'\n';
    ans=max-min+1;
    std::cout << ans<<'\n';
  }
  return 0;
}
