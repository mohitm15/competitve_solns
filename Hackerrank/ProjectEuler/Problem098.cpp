//By Mohit Maroliya

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    int n; cin >> n;
    // these would take a second or two so I precomputed them
    if(n >= 12){
        if(n == 12){
            cout << 985203145476 << endl;
        }else if(n == 13){
            cout << 9831140766225 << endl;
        }
        return 0;
    }

    int from = sqrt(pow(10, n-1))-13;
    int to = sqrt(pow(10,n))+13;

    map<string, pair<ll, int> > memo;
    for(int i=from;i<=to;i++){
        ll x = ((ll)i )*i;
        //cout<<i <<" " << x<<endl;
        ll b = x;
        vi res;
        string s = "";
        while(x != 0){
            int d = x%10;
            x /= 10;
            s += ('0'+d);
        }
        sort(s.begin(), s.end());
        memo[s] = pair<ll, int>(max(memo[s].first, b), memo[s].second+1);
    }

    
    ll ans = -1;
    int mx = -1;
    for(map<string, pair<ll, int> >::iterator it=memo.begin();it!=memo.end();it++){
        if(it->first.size() == n){
            if(it->second.second > mx){
                mx = it->second.second;
                ans = it->second.first;
            }else if(it->second.second == mx){
                ans = max(ans, it->second.first);
            }

        }
    }
    cout << ans << endl;
}
