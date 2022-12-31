/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1770/submission/187416748
 * Submitted at: 2022-12-31 16:04:34
 * Problem URL: https://codeforces.com/contest/1770/problem/C
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
 void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      cout << "No" << endl;
      return;
    }
  }
  for (int mod = 2; mod <= n / 2; mod++) {
    vector<ll> cnt(mod, 0);
    rep(i, n) cnt[a[i] % mod]++;
    if (*min_element(cnt.begin(), cnt.end()) > 1) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}