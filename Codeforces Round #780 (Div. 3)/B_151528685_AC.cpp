/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1660/submission/151528685
 * Submitted at: 2022-03-31 23:51:44
 * Problem URL: https://codeforces.com/contest/1660/problem/B
 * Result: AC
 * Execution Time: 389 ms
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
  sort(a.rbegin(), a.rend());
  if (n == 1) {
    puts(a[0] >= 2 ? "No" : "Yes");
    return;
  }
  if (a[0] - a[1] >= 2) {
    puts("No");
    return;
  }
  puts("Yes");
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}