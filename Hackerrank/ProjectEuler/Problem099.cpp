//By mohit marliya

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii v;
const double EPS = 1e-6;

int cmp(ii a, ii b){ //is left < right ?
    double c = a.first; // base
    double d = b.first; // base
    return a.second*log(c) <= b.second*log(d) + EPS;

}

void quickSort(int from, int to){
    if(from >= to){
        return;
    }

    ii p = v[to];
    int mid = from;
    for(int i=from;i<to;i++){
        if(cmp(v[i], p)){
            swap(v[i], v[mid]);
            mid++;
        }
    }

    swap(v[to], v[mid]);
    quickSort(from, mid-1);
    quickSort(mid+1, to);
}

int main(){
    int n; cin >> n;
    v = vii(n);
    for(int i=0;i<n;i++){
        int b, e; cin >> b >> e;
        v[i] = ii(b, e);
    }
    quickSort(0, n-1);
    int k; cin >> k;
    k--;
    cout << v[k].first <<" "<<v[k].second << endl;
}
