/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156894484
 * Submitted at: 2022-05-12 16:31:41
 * Problem URL: https://codeforces.com/contest/1676/problem/A
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
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  string s;
  cin >> s;
  if (accumulate(s.begin(), s.begin() + 3, 0) == accumulate(s.begin() + 3, s.end(), 0)) {
    puts("Yes");
  }
  else {
    puts("No");
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}