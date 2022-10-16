/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1744/submission/176584918
 * Submitted at: 2022-10-17 01:38:04
 * Problem URL: https://codeforces.com/contest/1744/problem/E1
 * Result: CH
 * Execution Time: 15 ms
 */

#pragma target("avx2")
#pragma optimize("O3")
#pragma optimize("unroll-loops")

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

  for (ll l = 1; l * a * b <= c * d; l++) {
    for (ll x = a + 1; x <= min(l * a * b, c); x++) {
      if ((l * a * b) % x == 0) {
        ll y = (l * a * b) / x;
        if (b < y && y <= d) {
          cout << x << " " << y << endl;
          return;
        }
      }
    }
  }

  cout << -1 << " " << -1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}