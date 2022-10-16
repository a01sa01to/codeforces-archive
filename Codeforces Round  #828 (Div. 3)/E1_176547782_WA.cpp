/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1744/submission/176547782
 * Submitted at: 2022-10-17 00:33:05
 * Problem URL: https://codeforces.com/contest/1744/problem/E1
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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  // m, n >= 2
  // x = ma, y = nb
  if (a * 2 <= c && b * 2 <= d) {
    printf("%lld %lld\n", a * 2, b * 2);
    return;
  }
  // x = ab, y = n
  if (a * b <= c && b != 1) {
    printf("%lld %lld\n", a * b, b + 1);
    return;
  }
  // x = mab, y = n
  if (2 * a * b <= c) {
    printf("%lld %lld\n", 2 * a * b, b + 1);
    return;
  }
  // x = 1, y = ab
  if (a * b <= d && a != 1) {
    printf("%lld %lld\n", a + 1, a * b);
    return;
  }
  // x = m, y = nab
  if (2 * a * b <= d) {
    printf("%lld %lld\n", a + 1, 2 * a * b);
    return;
  }

  for (ll m = b / a; a * m <= d; m++) {
    // x = b, y = na
    if (a < b && b <= c && b < a * m && a * m <= d) {
      printf("%lld %lld\n", b, a * m);
      return;
    }
  }
  for (ll m = a / b; b * m <= c; m++) {
    // x = mb, y = a
    if (b < a && a <= d && a < b * m && b * m <= c) {
      printf("%lld %lld\n", b * m, a);
      return;
    }
  }
  for (ll m = a / b; b * m <= c; m++) {
    for (ll n = b / a; a * n <= d; n++) {
      // x = mb, y = na
      if (a < b * m && b * m <= c && b < a * n && a * n <= d) {
        printf("%lld %lld\n", b * m, a * n);
        return;
      }
    }
  }

  printf("%d %d\n", -1, -1);
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}