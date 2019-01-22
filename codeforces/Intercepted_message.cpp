#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define LL long long int
int main()
{
    int n, m, blocks, ans = 0;
    vector<int> X;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> blocks;
        X.push_back(blocks);
    }
    LL xsum = 0, ysum = 0;
    for(int j = 0, i = 0; j < m; j++)
    {
        cin >> blocks;
        ysum += blocks;
        while(1)
        {
            if(xsum < ysum) xsum += X[i], i++;
            if(xsum == ysum)
            {
                ans++, xsum = 0, ysum = 0;
                break;
            }
            if(xsum > ysum) break;
        }
    }
    cout << ans << endl;

    return 0;
}
