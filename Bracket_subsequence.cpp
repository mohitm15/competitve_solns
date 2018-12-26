#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    string s;cin>>s;
    ll torem=n-k; //pairs to be deleted * 2
    stack<char> S;
    int i=0;
    for(i=0; i<s.length()&&torem; i++){
        if(s[i]=='('){
            S.push('(');
            continue;
        }
        S.pop();
        torem-=2; //removed one pair thus removing 1*2 from torem
    }
    string ans="";
    while(!S.empty()){ //because all will be '('
        ans.push_back('(');
        S.pop();
    }
    for(i;i<s.length();i++){
        ans.push_back(s[i]);
    }
    cout << ans << endl;
    return 0;
}
