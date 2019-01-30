//By Mohit Maroliya

//contest: Codeforces Round #529 (Div. 3), problem: (A) Repeating Cipher, Accepted, #

#include<iostream>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int t;
std::cin >> t;
char c[t];
f(i,t)
{
  std::cin >> c[i];
}
int s=0;
f(i,t)
{
s+=i;
if(s>=t)
break;
else
std::cout << c[s];
}
std::cout << '\n';
return 0;
