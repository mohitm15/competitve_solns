/* SOLUTION BY MOHTI MAROLIYA */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define INF 1e18
#define SIZE 31
using namespace std;

long long int money[SIZE];

int main()
{
    ios::sync_with_stdio(false);
    int typeNum, reqNum;
    cin >> typeNum >> reqNum;
    for (int i = 0; i < typeNum; i++)
    {
        cin >> money[i];
    }
    for (int i = typeNum; i < SIZE; i++)
    {
        money[i] = INF;
    }

    for (int i = 1; i < SIZE; i++)
    {
        money[i] = min(money[i], money[i - 1] * 2);
    }

    long long int ans = 0;
    for (int i = 0; i < SIZE - 1; i++)
    {
        if ((reqNum & (1 << i)) > 0)
        {
            ans += money[i];
        }
        ans = min(ans, money[i + 1]);
    }
    if ((reqNum & (1 << (SIZE - 1))) > 0)
    {
        ans += money[SIZE - 1];
    }
    cout << ans << endl;
    return 0;
}
