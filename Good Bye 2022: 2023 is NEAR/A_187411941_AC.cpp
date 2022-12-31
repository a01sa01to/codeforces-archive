/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1770/submission/187411941
 * Submitted at: 2022-12-31 15:14:05
 * Problem URL: https://codeforces.com/contest/1770/problem/A
 * Result: AC
 * Execution Time: 390 ms
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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  rep(i, n) pq.push(a[i]);
  rep(i, m) {
    pq.pop();
    pq.push(b[i]);
  }
  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}