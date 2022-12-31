/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1770/submission/187412574
 * Submitted at: 2022-12-31 15:21:24
 * Problem URL: https://codeforces.com/contest/1770/problem/B
 * Result: AC
 * Execution Time: 46 ms
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
  int n, k;
  cin >> n >> k;
  vector<int> ans(2 * n);
  rep(i, n) ans[2 * i] = n - i;
  rep(i, n) ans[2 * i + 1] = i + 1;
  Debug(ans);
  rep(i, n) cout << ans[i] << " ";
  cout << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}