// SOLN BY MOHIT MAROLIYA
#include <bits/stdc++.h>
using namespace std;
vector <int> ara;
int hcf(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
int main ()
{
   int n, x, k = 0;
   scanf (" %d ", &n);
   for (int i = 0; i < n; i++) {
      scanf (" %d", &x);
      if (i == 0) {ara.push_back(x); continue;}
      if (hcf (ara.back(), x) != 1) {
         ara.push_back (1);
         ara.push_back (x);
         k++;
      }
      else ara.push_back (x);
   }
   printf ("%d\n", k);
   for (int i = 0; i < ara.size(); i++) {
      if (i == 0) cout << ara[i];
      else cout << " " << ara[i];
   }
   printf ("\n");
   return 0;
}
