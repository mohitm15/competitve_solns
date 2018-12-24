//Soln BY MOHIT MAROLIYA


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

//Sieve
#define sieveMax 50000 //maximum for which u need primality test
vector<int> Prime;
void sieve(){
    bool neverMakeThisName[sieveMax];
    memset(neverMakeThisName,false, sizeof(neverMakeThisName));
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=4; i<sieveMax; i+=2) neverMakeThisName[i]=true;

    for(int i=3; i<=sqrt(sieveMax); i+=2)
        if(neverMakeThisName[i]==false) {
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }

    for(int i=0; i<sieveMax; i++) if(neverMakeThisName[i]==false) Prime.push_back(i);
}
//end Sieve

//set having all prime factors of (A1,B1)
set<int> probables;
void findPrimeFactors(ll temp){
    for(int i=0; i<Prime.size() && Prime[i]*Prime[i]<=temp; i++){
        if(temp%Prime[i]) continue;
        while((temp%Prime[i])==0){
            temp/=Prime[i];
        }
        probables.insert(Prime[i]);
    }
    if(temp>1){
        probables.insert(temp);
    }
}

int main(){
    fast_cin;
    int n;cin>>n;
    pair<ll,ll> arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i].f>>arr[i].s;
    }

    //ignore below three line
    //and function if you use something
    //different for finding Prime Factors
    sieve();
    findPrimeFactors(arr[0].f);
    findPrimeFactors(arr[0].s);
    //end ignore

    for(auto it=probables.begin(); it!=probables.end(); it++){
        bool ans=true;
        ll val=*it;
        //val can be possible solution
        for(int i=0; i<n; i++){
            if((arr[i].f%val)==0 || (arr[i].s%val)==0){
                continue;
            }
            //if even one pair is not
            //divisble, this can't
            //be our solution
            ans=false;
            break;
        }
        if(ans){
            cout << val << endl;
            return 0;
        }
    }
    //none of probables divided all pairs
    //therefore no solution exists
    cout << -1 << endl;
    return 0;
}
