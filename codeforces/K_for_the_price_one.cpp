// Contest: Codeforces Round #610 (Div. 2), problem: (B2) K for the Price of One (Easy+Hard Version)
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
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int
#define ld long double

using namespace std;


int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, p, k;
        cin >> n >> p >> k;
        int pref = 0;
        int ans = 0;
        vector<int> a(n);
        f0(i,n) cin >> a[i];
        sort(a.begin(), a.end());
        f0(i,k)
        {
            int sum = pref;
            if (sum > p) break;
            int cnt = i;
            for (int j = i + k - 1; j < n; j += k) 
            {
                if (sum + a[j] <= p)
                {
                    cnt += k;
                    sum += a[j];
                } 
                else
                {
                    break;
                }
            }
            pref += a[i];
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
}
