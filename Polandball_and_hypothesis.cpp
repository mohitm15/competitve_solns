#include <iostream>
#include <cmath>

using namespace std;

#define sf scanf
#define pf printf

int m = 1;

void prime (int n)
{
    int i,rem,res,check;

    check = 1, res = n*m + 1, i = sqrt(res);

    if (res % 2 == 0)
        check = 0;
    else
    {
        for (rem = 2; rem <= i; rem++)
        {
            if (res % rem == 0)
            {
                check = 0;
                break;
            }
        }
    }

    if (check == 0)
        cout << m << endl;
    else
    {
        m = m + 1;
        prime (n);
    }
}

int main (void)
{
    int n,i,rem,check;

    while (cin >> n)
    {
        if (n & 1)
        {
            if (n == 1)
                cout << 3 << endl;
            else
                cout << 1 << endl;
        }
        else
            prime (n);
    }

    return 0;
}
