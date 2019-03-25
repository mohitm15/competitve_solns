//March Cook-Off 2019-Problem:01

//By mohit maroliya

#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
int main() {
 
	int n,q; cin>>n>>q;
 
	vector<int> v;
 
	int temp; cin>>temp;
	int nn = temp;
	v.pb(temp);
	int prev = temp;
 
	for(int i=1;i<n;i++) {
		cin>>temp;
		nn = nn^temp;
		v.pb(prev^temp);
		prev = prev^temp;
	}
 
	v.pb(prev^nn);
 
	// for(int i=0;i<n+1;i++) {
	// 	cout<<v[i]<<" ";
	// }
	// cout<<endl;
 
 
	for(int i=0;i<q;i++){
		cin>>temp;
		cout<<v[temp%(n+1) - 1]<<endl;
	}
 
	return 0;
}
