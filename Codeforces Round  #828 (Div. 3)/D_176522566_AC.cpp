/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1744/submission/176522566
 * Submitted at: 2022-10-16 23:58:48
 * Problem URL: https://codeforces.com/contest/1744/problem/D
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
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  ll cnt = 0;
  rep(i, n) {
    int a;
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
      cnt++;
    }
  }
  ll ans = 0;
  set<ll> used;
  for (int i = 60; i >= 0; i--) {
    if (cnt >= n) break;
    if ((1LL << i) <= n) {
      for (int j = 1; (1LL << i) * j <= n; j++) {
        if (cnt >= n) break;
        if (used.count((1LL << i) * j)) continue;
        used.insert((1LL << i) * j);
        cnt += i;
        ans++;
      }
    }
  }
  cout << (cnt >= n ? ans : -1) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}