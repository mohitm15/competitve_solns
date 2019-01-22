//contest: Codeforces Round #284 (Div. 2), problem: (B) Lecture, Accepted, #



#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define pf printf
#define sf scanf
#define loop(i, n) for(i=0; i<(n); i++)
#define MAX 100
map<string, string> mp;

int main()
{
    //freopen("in.txt","r",stdin);
    int n, m;
    string s1, s2;
    cin >> n >> m;
    while(m--)
    {
        cin >> s1 >> s2;
        if(s1.length()>s2.length())
            mp[s1] = s2;
        else
            mp[s1] = s1;
    }
    while(n--)
    {
        cin >> s1;
        cout << mp[s1] << " ";
    }
    cout << endl;
    return 0;
}
