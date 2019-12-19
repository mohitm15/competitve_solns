// contest: Codeforces Round #606 (Div. 2, based on Technocup 2020 Elimination Round 4), problem: (D) Let's Play the Words?, Accepted, #
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 
// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░░▀░░░░░░░░▀░░█░█░░░░░
// ░░░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░░
// ░░░░░░█░█░░░░▀░░░░▀░░░░█░█░░░░░
// ░░░░░░█░█▄░░░░▀░░▀░░░░▄█░█░░░░░
// ░░░░░░█░█░░░░░░██░░░░░░█░█░░░░░
// ░░░░░░█░▀░░░░░░░░░░░░░░▀░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░
// ░░░░░░▀░░░░░░░░░░░░░░░░░░▀░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#include<bits/stdc++.h>
#define next cout<<endl
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(j,n) for(int j=n-1;j>=0;j--)
#define ll long long int

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        set<string> s01;
        set<string> s10;
        vector<bool> u(2);
        f0(i, n) {
            cin >> s[i];
            if (s[i][0] == '0' && s[i].back() == '1')
                s01.insert(s[i]);
            if (s[i][0] == '1' && s[i].back() == '0')
                s10.insert(s[i]);
            u[s[i][0] - '0'] = u[s[i].back() - '0'] = true;
        }
        if (u[0] && u[1] && s01.size() == 0 && s10.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        vector<int> rev;
        if (s01.size() > s10.size() + 1) 
        {
            f0(i, n)
                if (s[i][0] == '0' && s[i].back() == '1') {
                    string ss(s[i]);
                    reverse(ss.begin(), ss.end());
                    if (s10.count(ss) == 0)
                        rev.push_back(i);
                }
        } else if (s10.size() > s01.size() + 1) {
            f0(i, n)
                if (s[i][0] == '1' && s[i].back() == '0') {
                    string ss(s[i]);
                    reverse(ss.begin(), ss.end());
                    if (s01.count(ss) == 0)
                        rev.push_back(i);
                }
        }
        int ans = max(0, (int(max(s01.size(), s10.size())) - int(min(s01.size(), s10.size()))) / 2);
        cout << ans << endl;
        f0(i, ans)
            cout << rev[i] + 1 << " ";
        next;
    }
    return 0;
}
