//By Mohit Maroliya


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;


int isPerm(int a, int b){
    vi as(10, 0);
    while(a != 0){
        as[a%10]++;
        a /= 10;
    }
    while(b != 0){
        as[b%10]--;
        b /= 10;
    }
    for(int i=0;i<10;i++){
        if(as[i] != 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    vi ps(n, 0);
    vi eus(n);
    for(int i=0;i<n;i++) eus[i] = i;

    for(int i=2;i<n;i++){
        if(!ps[i]){
            for(int j=i;j<n;j+=i){
                ps[j] = 1;
                eus[j] -= eus[j]/i;
            }
        }
    }

    vi v(n);
    int best = -1;
    for(int i=2;i<n;i++){
        v[i] = eus[i];
        if(best == -1 || double(i)/v[i] < double(best)/v[best]){
            if(isPerm(v[i], i)){
                best = i;
            }
        }
    }
    cout << best <<endl;
}
