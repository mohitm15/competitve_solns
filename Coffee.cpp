#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define INF 10000007

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

int n, m, d, x, day[200005], mday[200005], comp, cind, last;
pii a[200005];

bool cmp(pii p1, pii p2){
    return p1.first<p2.first;
}

main(){
    cin>>n>>m>>d;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[i]= mp(x,i);
    }

    if(n==1){
        cout<<"1"<<endl<<"1"<<endl;
        return 0;
    }

    sort(a,a+n,cmp);

    int low= a[0].first, low_i= 0, high= 0;
    day[0]= 1;

    for(int i=0;i<n;i++)
    {
        if(a[i].first-low> d){
            day[i]= day[low_i];
            mday[a[i].second]= day[i];

            low_i= low_i+1;
            low= a[low_i].first;
        }

        else{
            day[i]= ++high;
            mday[a[i].second]= day[i];
        }
    }

    cout<<high<<endl;
    cout<<mday[0];
    for(int j=1;j<n;j++)
    {
        cout<<" "<<mday[j];
    }
    puts("");
}
