//DAY 5

#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n,p;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=1;i<=10;i++)
{
    p=i*n;
    cout<<n<<" x "<<i<<" = "<<p<<'\n';
}
    return 0;
}
