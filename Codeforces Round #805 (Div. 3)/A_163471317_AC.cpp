/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1702/submission/163471317
 * Submitted at: 2022-07-10 23:38:29
 * Problem URL: https://codeforces.com/contest/1702/problem/A
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
  int m;
  cin >> m;
  for (int i = 1000000000; i >= 1; i /= 10) {
    if (m >= i) {
      cout << m - i << endl;
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}