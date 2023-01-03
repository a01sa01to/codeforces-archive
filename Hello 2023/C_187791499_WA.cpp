/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1779/submission/187791499
 * Submitted at: 2023-01-04 00:39:07
 * Problem URL: https://codeforces.com/contest/1779/problem/C
 * Result: WA
 * Execution Time: 374 ms
 */

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
 void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  ll sum = 0;
  rep(i, m) {
    sum += a[m - i - 1];
    if (sum > 0 && i != m - 1) {
      ans++;
      sum -= 2 * a[m - i - 1];
    }
  }
  Debug(ans);
  sum = 0;
  rep(i, n - m) {
    sum += a[i + m];
    Debug(i + m, a[i + m], ans, sum);
    if (sum < 0) {
      ans++;
      sum -= 2 * a[i + m];
    }
  }
  cout << ans << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}