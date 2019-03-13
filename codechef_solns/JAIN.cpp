//March Long Challenge- Problem 3
//By Mohit Maroliya

#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::string s[n];
    std::string stest,res;
    getline(cin,stest);
    for(int i=0;i<n;i++)
    getline(cin,s[i]);
    int a=0,e=0,k=0,o=0,u=0,cnt=0;
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        a=(s[i]+s[j]).find('a')+1;
        e=(s[i]+s[j]).find('e')+1;
        k=(s[i]+s[j]).find('i')+1;
        o=(s[i]+s[j]).find('o')+1;
        u=(s[i]+s[j]).find('u')+1;
        if((a!=0)&&(e!=0)&&(k!=0)&&(o!=0)&&(u!=0))
        cnt++;
      }
     //std::cout << '\n';
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
