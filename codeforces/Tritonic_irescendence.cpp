//Soln BY MOHIT MAROLIYA

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, ck=0,i;
    std::cin >> n;
 string arr;
 cin>>arr;
  if(arr[0]=='?'|| arr[n-1]=='?')ck = 1;
 for(i=1; i<n; i++)
 {
 if(arr[i]=='?'&&(arr[i-1] == arr[i+1] || arr[i-1]=='?'))
 ck = 1;
 else if(arr[i]==arr[i-1])
 {
 ck = 0;
 break;
 }
 }
 if(ck)
  printf("Yes\n");
 else
 printf("No\n");
}
