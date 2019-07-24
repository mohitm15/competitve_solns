// Codechef May Cookoff 2019 : Problem3
// By Mohit Maroliya 
// Failing in testcase : 
// 200 299 100
// My ans=1 ; correct ans =0;

#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ull unsigned long long int
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ull l,r,g,cnt=0;cin>>l>>r>>g;
        if(g>r){ cout<<"0"<<endl;}
        else if(l==r && r==g){ cout<<"1"<<endl;}
        else 
        { 
            for(ull i=g;i<=r;)
            {
                //cout<<"i = "<<i<<"---";
                if(i>=l)
                {
                    cnt++;
                    //cout<<"i = "<<i<<"---";
                    //cout<<endl;
                }
                i+=g;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
