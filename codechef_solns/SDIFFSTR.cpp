//  ICPC Asia-Amritapuri Onsite Replay Contest 2019 : Problem 2
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
 
#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(long long int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=(int)s.size(),i,tm,k,c;
        cin>>k;
        c=k;
        vector<bool> v(26,true);
        for(i=0;i<n;i++){
            tm=s[i]-'a';
            v[tm]=false;
        }
        i=0;
        while(k){
            if(!v[i]){
                v[i]=true;
                k--;
            }
            i++;
        }
        if(26-n+c<n){
            cout<<"NOPE\n";
            continue;
        }
        i=0;
        while(n){
            if(v[i]){
                cout<<char(97+i);
                n--;
            }
            i++;
        }
        cout<<endl;
    }

    return 0;
}
