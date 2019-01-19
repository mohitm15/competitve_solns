//By Mohit Maroliya


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;



int M = 125875;
int N = 2000000;
vi getDs(int x){
    vi ans(10, 0);
    while(x != 0){
        int d = x%10;
        x /= 10;
        ans[d]++;
    }
    return ans;
}
int main(){
    int n, k; cin >> n >> k;
    for(int i=1;i<=n;i++){
        int same = true;
        vi b = getDs(i);
        for(int j=2;j<=k && same;j++){
            vi p = getDs(j*i);
            if(p != b){
                same =false;
                break;
            }
        }
        if(same){
            for(int j=1;j<=k;j++){
                cout << (i*j)<<" ";
            }
            cout << endl;
        }
    }
}
