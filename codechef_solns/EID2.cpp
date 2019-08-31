//COdechef August lunchtime 2019 : Problem 1
//By mohit maroliya

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a[3],c[3],flag=0;
    for(int i=0;i<3;i++)
    {
      cin>>a[i];
    }
        for(int i=0;i<3;i++)
    {
      cin>>c[i];
    }
    if((a[0]<a[1] && c[0]<c[1]) || (a[0]==a[1] && c[0]==c[1]) || (a[0]>a[1] && c[0]>c[1]))
    flag++;
    if((a[1]<a[2] && c[1]<c[2]) || (a[1]==a[2] && c[1]==c[2]) || (a[1]>a[2] && c[1]>c[2]))
    flag++;
    if((a[0]<a[2] && c[0]<c[2]) || (a[0]==a[2] && c[0]==c[2]) || (a[0]>a[2] && c[0]>c[2]))
    flag++;
    if(flag == 3)
    cout<<"FAIR"<<endl;
    else
    {
      cout<<"NOT FAIR"<<endl;
    }
    
  }
  return 0;
}
