//contest: Codeforces Round #488 by NEAR (Div. 2), problem: (A) Fingerprints, Happy New Year!, #
 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> c,d;

int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        int t;
        cin>>t;
        c.push_back(t);
    }
    for(int i=0;i<b;i++){
        int t;
        cin>>t;
    d.push_back(t);

    }

    for(int i=0;i<a;i++){
      if(count(d.begin(),d.end(),c[i])>0){
            cout<<c[i]<<" ";
       }
    }

    return 0;
}
