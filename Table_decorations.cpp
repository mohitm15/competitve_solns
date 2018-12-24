
 #include <algorithm>
#include <iostream>

using namespace std;
typedef long long int ll;
int main(){
    ll arr[3];
    for(int i=0; i<3; i++)
    {
       cin>>arr[i];
    }
    sort(arr,arr+3);
    if(arr[0]+arr[1]<=arr[2]/2)
    {
		cout<<arr[0]+arr[1];
	  }
	else
  {
		cout<<((arr[0]+arr[1]+arr[2])/3);
	}
  return 0;
