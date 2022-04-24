/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154801690
 * Submitted at: 2022-04-24 11:22:07
 * Problem URL: https://codeforces.com/contest/1669/problem/A
 * Result: AC
 * Execution Time: 30 ms
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
  int r;
  cin >> r;
  int ans = 0;
  if (r >= 1900)
    ans = 1;
  else if (r >= 1600)
    ans = 2;
  else if (r >= 1400)
    ans = 3;
  else
    ans = 4;
  printf("Division %d\n", ans);
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}