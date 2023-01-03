/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1779/submission/187804892
 * Submitted at: 2023-01-04 01:01:34
 * Problem URL: https://codeforces.com/contest/1779/problem/C
 * Result: WA
 * Execution Time: 327 ms
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
  for (int i = m - 1; i > 0; i--) {
    sum += a[i];
    Debug(sum);
    if (sum > 0) {
      assert(a[i] > 0);
      ans++;
      sum -= 2 * a[i];
      assert(sum <= 0);
    }
  }
  Debug(ans);
  sum = 0;
  for (int i = m; i < n; i++) {
    sum += a[i];
    Debug(i, a[i], ans, sum);
    if (sum < 0) {
      assert(a[i] < 0);
      ans++;
      sum -= 2 * a[i];
      assert(sum >= 0);
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