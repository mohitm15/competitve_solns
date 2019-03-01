//DAY 20

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int cnt = 0;
    // Write Your Code Here
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-1);j++)
        {
            int temp;
            if(a[j]>a[j+1])
            {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
              cnt++;  
            }
        }
        if(cnt == 0)
        break;
    }
    cout<<"Array is sorted in "<<cnt<<" swaps."<<endl;
    cout<<"First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[n-1]<<endl;
    return 0;
}
