/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1744/submission/176508954
 * Submitted at: 2022-10-16 23:43:31
 * Problem URL: https://codeforces.com/contest/1744/problem/B
 * Result: AC
 * Execution Time: 655 ms
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
  int n, q;
  cin >> n >> q;
  ll odd = 0, even = 0, oddcnt = 0, evencnt = 0;
  rep(i, n) {
    ll x;
    cin >> x;
    if (x % 2 == 0) {
      evencnt++;
      even += x;
    }
    else {
      oddcnt++;
      odd += x;
    }
  }
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 0) {
      if (x % 2 != 0) {
        odd += even + x * evencnt;
        oddcnt += evencnt;
        evencnt = 0;
        even = 0;
      }
      else {
        even += x * evencnt;
      }
    }
    else {
      if (x % 2 != 0) {
        even += odd + x * oddcnt;
        evencnt += oddcnt;
        oddcnt = 0;
        odd = 0;
      }
      else {
        odd += x * oddcnt;
      }
    }
    cout << even + odd << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}