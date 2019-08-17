//Codeforces Round 579 :Problem 2
//Mohit  maroliya
#include<bits/stdc++.h>
using namespace std;
#define f(i,N) for(int i=0;i<N;i++)
#define next cout<<endl
#define ull unsigned long long int
#define modulo 1000000007
int rectcheck(int a[],int n)
{
   int b[n/2];
   sort(a,a+(n));
   for(int i=0;i<n;i+2)
   {
       if(a[i]!=a[i+1]);
       return 0;
       b[i]=a[i];
   }
   int p=0,q=(n/2)-1,cnt=0;
   int prod = p*q;
   while(p<q)
   {
       p++;q--;
       if((b[p]*b[q]== prod))
       cnt++;
   }
   if(cnt == (n/2)-1)
    return 1;
    else
    return 0;
    
}
int main()
{
   int q;
   cin>>q;
   while(q--)
    {
        int num;
        cin>>num;
        int n = num*4;
        int a[n],ans;
        f(i,n) cin>>a[i];
        ans = rectcheck(a,n);
        if(ans == 0)
        cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
        }
    }
}
