//By Mohit MAroliya



#include <bits/stdc++.h>

using namespace std;

int prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i == 0) return false;
    }
    return true;
}
int p(int x){
    int d = 1;
    int digs = 0;
    while(d <= x){
        d *= 10;
        digs++;
    }
    d/=10;
    for(int k=0;k<digs;k++){
        x = (x%10)*d+(x/10);
        if(!prime(x)){
            return false;
        }
    }
    return true;
}
int main(){
    int n; scanf("%d", &n);
    int sum = 0;
    for(int i=2;i<n;i++){
        if(p(i)){
            sum += i;
            //cout << i <<endl;
        }
    }
    printf("%d\n", sum);
}
