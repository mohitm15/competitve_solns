//DAY 25

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool primeornot(int n) {
  int i, sqr;
  if (n == 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  sqr = sqrt(n);
  for (i = 2; i <= sqr; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    vector <int>arr(t);
    while(t--)
    { 
      int i=0;
      cin >> arr[i];
      bool f = primeornot(arr[i]);

      if (f) {
        cout << "Prime" << endl;
      } else {
        cout << "Not prime" << endl;
      }
      i++;
    }
    return 0;
}
