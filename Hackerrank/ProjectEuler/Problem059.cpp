//By Mohit Maroliya

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

bool allowed(char x){
    if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <='9')){
        return true;
    }
    char allowed[11] = {' ', ')','(', ';', ':', ',', '.', '\'', '?', '-', '!'};
    for(int i=0;i<11;i++){
        if(x == allowed[i]) return true;
    }
    return false;
}

int main(){
    int n; cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int a ='a';a<='z';a++){
        for(int b='a';b<='z';b++){
            for(int c='a';c<='z';c++){
                string key = ""; key += a; key += b; key += c;
                bool sat = true;
                for(int i=0;i<n;i++){
                    int x = v[i]^key[i%3];
                    if(!allowed(x)){
                        sat = false;
                        break;
                    }
                }
                if(sat){
                    cout << key <<endl;
                    /*for(int i=0;i<n;i++){
                        cout << char(v[i]^key[i%3]) <<" ";
                    }
                    cout << endl;*/
                }
            }
        }
    }
}
