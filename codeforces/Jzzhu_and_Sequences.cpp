//BY Mohit MAroliya

//contest: Codeforces Round #257 (Div. 2), problem: (B) Jzzhu and Sequences, Accepted, #
 #include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long int x, y, z, n, tmp, a[7]={0}, ans;
    const int md=1e9+7;
     std::cin >> x>>y>>n;
    z=y-x, a[1]=x, a[2]=y;
    for(int i=3; i<=6; i++)
    {
        tmp=x, x=y, y=z, z=y-x, a[i%6]=y;
    }
    if(a[n%6]>=0)
    std::cout << a[n%6]%md << '\n';
    else
    std::cout << (md+a[n%6]%md)%md << '\n';
    return 0;
}
