/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1660/submission/151509060
 * Submitted at: 2022-03-31 23:37:40
 * Problem URL: https://codeforces.com/contest/1660/problem/A
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
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 0)
    cout << 1 << endl;
  else
    cout << 2 * b + a + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}