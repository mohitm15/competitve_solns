// Codechef August Long Challenge 2019 : Problem 4
//Mohit Maroliya


#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=1;i<=n;i++)
#define ull unsigned long long int


int mini(int a,int b)
{
    if(a<=b)
    return a;
    else
    return b;
}
int maxi(int a,int b)
{
    if(a>=b)
    return a;
    else
    return b;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0,incre=0,s,e;
        cin>>n;
        int a[n+1]={0},c[n+1],h[n+1];
        c[0]=0;h[0]=0;
        queue<int> start;
        queue<int> end;
        f(i,n) cin>>c[i];
        f(i,n) cin>>h[i];
        f(i,n)
        {
          s=i-c[i];
          e=i+c[i];
          {
            start.push(maxi(1,(i-c[i])));
            end.push(mini(n,(i+c[i])));
          }         
        }
        f(k,n)
        {
            a[k]=incre;
        }
        while(start.empty()!= true)
        {
          a[start.front()] +=1;
          if(end.front() != n)
            a[end.front() + 1] -= 1;
          start.pop();end.pop();
        }

        for(int i=1;i<=n;i++)
        {
            a[i]=a[i]+a[i-1];
        }
        sort(a+1,a+n+1);
        sort(h+1,h+n+1);
        for(int i=0;i<n;i++)
        {
            if(a[i]==h[i])
            cnt++;
        }
        if(cnt==n)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
