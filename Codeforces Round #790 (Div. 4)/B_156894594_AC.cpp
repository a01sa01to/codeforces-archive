/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156894594
 * Submitted at: 2022-05-12 16:33:06
 * Problem URL: https://codeforces.com/contest/1676/problem/B
 * Result: AC
 * Execution Time: 78 ms
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
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll minim = *min_element(a.begin(), a.end());
  ll ans = 0;
  rep(i, n) ans += a[i] - minim;
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}