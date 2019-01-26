// By Mohit Maroliya

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef vector<int> vi;

const int N = 1e7;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    vi sol(N, 0);
    // Pythagorean triples
    for(int i=1;i*i<=N;i++){
        for(int j=i+1;j<N;j++){
            if((j-i)%2 == 1 && gcd(i, j) == 1){
                int a = j*j-i*i;
                int b = 2*i*j;
                int c = i*i+j*j;
                if(a+b+c >= N) break;

                int k = 1;
                while(a*k+b*k+c*k < N){
                    sol[a*k+b*k+c*k]++;
                    k++;
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        if(sol[i] > 1) sol[i] = 0; //invalid solutions
    }

    // Prefix sum
    for(int i=1;i<N;i++){
        sol[i] += sol[i-1];
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << sol[n] <<endl;
    }

}
