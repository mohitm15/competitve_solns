#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int input[500100];
    long long int sum = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", input + i);
        sum += input[i];
    }

    if(sum % 3 != 0)
        printf("0\n");
    else
    {
        long long int buf = 0;
        long long int part = sum / 3;
        int pos[500100];
        for(int i=0; i<n; i++)
        {
            if(i == 0)
                pos[0] = 0;
            else
                pos[i] = pos[i-1];
            buf += input[i];
            if(buf == part)
                pos[i]++;
        }

        buf = 0;
        long long int ans = 0;
        for(int i=n-1; i>=2; i--)
        {
            buf += input[i];
            if(buf == part)
            {
                ans += pos[i-2];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
