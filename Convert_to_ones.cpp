#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

int n, a[N], x, y;

int main() {
  scanf("%d%d%d", &n, &x, &y);
  int m = 1;
  scanf("%1d", &a[1]);
  for (int i = 2; i <= n; i++) {
    m++;
    scanf("%1d", &a[m]);
    if (a[m] == a[m-1]) m--;
  }

  if (a[m]) m--;
  if (a[1]) m--;

  ll a0 = (m+1)/2, a1 = m-a0;
  ll ans = 0;
  if (a0) ans = min(a1 * x + max(a0-a1, 0ll)*y, a0 * y);
  printf("%lld\n", ans);

  return 0;
}
