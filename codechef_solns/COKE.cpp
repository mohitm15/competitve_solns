//CodeChef : August Cook-off 2019 : Problem 1
// BY mohit maroliya

#include<bits/stdc++.h>
using namespace std;


int main(){
	fast
	int n,m,k,l,r,t;
	cin>>t;
	int c,p;
	bool ans=0;
	while(t--){
		cin>>n>>m>>k>>l>>r;
		bool ans=0;
		int val=INT_MAX;
		for(int i=0;i<n;i++) {
			cin>>c>>p;
			int temp=0;
			if(c<k){
				temp=min(k,c+m);
			}
			else temp=max(k,c-m);
			if(temp>=l&&temp<=r){
				ans=1;
				val=min(val,p);
			}
		}
		if(ans)
			cout<<val<<endl;
		else 
			cout<<"-1"<<endl;
	}
}
