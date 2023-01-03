/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1779/submission/187732125
 * Submitted at: 2023-01-03 23:43:22
 * Problem URL: https://codeforces.com/contest/1779/problem/A
 * Result: AC
 * Execution Time: 62 ms
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
  string s;
  cin >> s;
  if (s.find("RL") == string::npos) {
    auto a = s.find("LR");
    if (a == string::npos) {
      cout << -1 << endl;
    }
    else {
      cout << a + 1 << endl;
    }
  }
  else {
    cout << 0 << endl;
  }
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}