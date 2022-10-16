/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1744/submission/176577045
 * Submitted at: 2022-10-17 01:23:12
 * Problem URL: https://codeforces.com/contest/1744/problem/E1
 * Result: TLE
 * Execution Time: 4000 ms
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

  for (ll x = a + 1; x <= c; x++) {
    for (ll y = b + 1; y <= d; y++) {
      if ((x * y) % (a * b) == 0) {
        cout << x << " " << y << endl;
        return;
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