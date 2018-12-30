//contest: Educational Codeforces Round 40 (Rated for Div. 2), problem: (A) Diagonal Walking, Happy New Year!, #
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n,p1,p2,r=0;
  std::cin >> n;
  char ch[n];
  for(int i=0;i<n;i++)
  {
    std::cin >> ch[i];
  }
  for(int j=1;j<n;j++)
  {
    //current id R
    if(ch[j-1]=='U' && ch[j]=='R')
    {
       r+=1;
       j++;
      // if(ch[j]=='U' && ch[j+1]=='R')
         //r+=1;
    }
    //current is U
    else if(ch[j-1]=='R' && ch[j]=='U')
    {
       r+=1;
       j++;
      // if(ch[j]=='R' && ch[j+1]=='U')
        // r+=1;
    }

  }
   p1=count(ch,ch+n,'R');
      p2=count(ch,ch+n,'U');

  std::cout << (p1+p2)-r << '\n';

  return 0;
}
