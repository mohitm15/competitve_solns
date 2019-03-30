// Codechef March Lunchtime 2019:Problem 2
// By Mohit Maroliya

#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int block=ceil(((float)n)/k);
        int size = block*k;
        int a[size]={0},d,r;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long m=INT_MIN;
        for(int i=size-1;i>=size-k;i--){
            long long  sum=0;
            for(int j=i;j>=0;j-=k){
                sum+=a[j];
                m=max(m,sum);
            }
        }
        cout<<m<<endl;
        
    }
    return 0;
}
