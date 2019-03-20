//March Bileration #1 2019- Problem 1

//By mohit maroliya

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt=0;
  std::cin >> n;
  char ch[n];
  for(int i=0;i<n;i++)
  {
    std::cin >> ch[i];
    if(ch[i]=='a' )
    cnt1++;
    else if(ch[i]=='e')
    cnt2++;
    else if(ch[i]=='i')
    cnt3++;
    else if(ch[i]=='o')
    cnt4++;
    else if(ch[i]=='u')
    cnt5++;
  }
  if(n<4)
  std::cout << "No" << '\n';
  else
  {
   if(cnt1!=0 && cnt2!=0 && cnt3!=0 && cnt4!=0)
   std::cout << "Yes" << '\n';
   else if(cnt5!=0 && cnt2!=0 && cnt3!=0 && cnt4!=0)
   std::cout << "Yes" << '\n';
   else if(cnt5!=0 && cnt1!=0 && cnt3!=0 && cnt4!=0)
   std::cout << "Yes" << '\n';
   else if(cnt5!=0 && cnt2!=0 && cnt1!=0 && cnt4!=0)
   std::cout << "Yes" << '\n';
   else if(cnt5!=0 && cnt2!=0 && cnt3!=0 && cnt1!=0)
   std::cout << "Yes" << '\n';
   else
   std::cout << "No" << '\n';
  }
   return 0;
}
