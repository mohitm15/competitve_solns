//By Mohit Maroliya

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void func(char arr[], ll n) {
	int count = 0;
	if(arr[0] == '0' && arr[1] == '0') {
		arr[0] = '1';
		count++;
	}

	for(int i = 1; i < n - 1; i++) {
		if(arr[i] == '0' && arr[i - 1] == '0' && arr[i + 1] == '0') {
			arr[i] = '1';
			count++;
		}
	}

	if(arr[n - 2] == '0' && arr[n - 1] == '0') {
		count++;
	}
	cout << count;
}

int main() {
	ll test, n;
	char arr[200005];
	cin >> test;
	while(test--) {
	    cin >> n;
	    for(ll j = 0; j < n; j++) {
	        cin >> arr[j];
	    }
	    func(arr, n);
	    cout << "\n";
	}
	return 0;
}
