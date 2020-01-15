// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░  ░░░░░  ░░░█░░░░░
// ░░░░░░█░░░░░░ ░ ░░░ ░ ░░░█░░░░░
// ░░░░░░▀░░░░░░ ░░ ░ ░░ ░░░▀░░░░░
// ░░░░░░░░░░░░░ ░░░ ░░░ ░░░░░░░░░

// time limit exceeded in last 2 test cases.
 
#include<bits/stdc++.h>

#define f0(i,n) for(long long int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f2(i,n) for(int i=2;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>0;j--)
#define ll long long int
#define next cout<<endl
 
using namespace std;


int max(int a,int b)
{
    int ans = (a>=b)?a:b;
    return ans;
}

int min(int a,int b)
{
    int ans = (a<=b)?a:b;
    return ans;
}

int findKthSmallest(vector<int> const &v, int k)
{

    priority_queue<int, vector<int>> pq(v.begin(), v.begin() + k);

    for (int i = k; i < v.size(); i++)
    {

        if (v[i] < pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }

    return pq.top();
}
 int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> acopy(n);
    f0(i,n) cin>>a[i];
    acopy =a;
    f0(i,q)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int m,x;
            cin>>m>>x;
            a[m-1]=x;
            acopy[m-1]=x;
        }
        else if(t==2)
        {
            int k;
            cin>>k;
            cout<<findKthSmallest(a,k)<<endl;
            a=acopy;
        }
        // f0(j,n)
        // cout<<a[j]<<" ";
        // next;
    }
    return 0;
}
