//By Mohit Maroliya


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        ll n; scanf("%lld", &n);
        ll k = (n-1)/2;
        k--;
        ll ans = 1+24*(k%mod) + 18*(((k%mod)*((k+1)%mod))%mod);
        assert(ans > 0);
        ans %= mod;
        if((k+1)%3 == 0){
            ans += ((8*(((k+1)/3)%mod))%mod)  * (((k%mod) * ((2*k+1)%mod) )%mod);
        }
        else if(k%3 == 0){
            ans += (((8*((k+1)%mod))%mod)%mod) * ((((k/3)%mod)*((2*k+1)%mod))%mod);
        }else{
            assert((2*k+1)%3 == 0);
            ans += (((8*((k+1)%mod))%mod)%mod) * (((k%mod)*(((2*k+1)/3)%mod))%mod);
        }
        ans %= mod;
        ans += 24;
        assert(ans > 0);
        printf("%lld\n", ans%mod);
    }

}
