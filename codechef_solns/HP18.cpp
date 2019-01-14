//January Long Challenge 2019

#include <bits/stdc++.h>
using namespace std;

int removeCommon(int *ar, int n, int a, int b)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] % a == 0 && ar[i] % b == 0)
        {
            ar[i] = 0;
            k++;
        }
    }
    return k;
}

int remove(int *ar, int n, int e, int i)
{
    while (i < n)
    {
        if (ar[i] != 0 && ar[i] % e == 0)
        {
            ar[i] = 0;
            return i;
        }
        else
            i++;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];

        int bob = 0, alice = 0;
        int flag = removeCommon(ar, n, a, b);
        if (flag > 0)
        {
            while (true)
            {
                alice = remove(ar, n, b, alice);
                if (alice == -1)
                {
                    cout << "BOB" << endl;
                    break;
                }
                bob = remove(ar, n, a, bob);
                if (bob == -1)
                {
                    cout << "ALICE" << endl;
                    break;
                }
            }
        }
        else
        {
            while (true)
            {
                bob = remove(ar, n, a, bob);
                if (bob == -1)
                {
                    cout << "ALICE" << endl;
                    break;
                }
                alice = remove(ar, n, b, alice);
                if (alice == -1)
                {
                    cout << "BOB" << endl;
                    break;
                }
            }
        }
    }
}
