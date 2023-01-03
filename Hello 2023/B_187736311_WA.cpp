/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1779/submission/187736311
 * Submitted at: 2023-01-03 23:46:28
 * Problem URL: https://codeforces.com/contest/1779/problem/B
 * Result: WA
 * Execution Time: 0 ms
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
  if (n % 2 == 1) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    rep(i, n / 2) {
      cout << 1 << " " << -1 << " ";
    }
    cout << endl;
  }
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}