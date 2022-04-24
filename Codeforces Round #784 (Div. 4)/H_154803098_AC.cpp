/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154803098
 * Submitted at: 2022-04-24 11:55:15
 * Problem URL: https://codeforces.com/contest/1669/problem/H
 * Result: AC
 * Execution Time: 374 ms
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
  int n, k;
  cin >> n >> k;
  vector<int> cnt(31, 0);
  rep(_, n) {
    int x;
    cin >> x;
    rep(i, 31) {
      if (x & (1 << i)) cnt[i]++;
    }
  }
  reverse(cnt.begin(), cnt.end());
  rep(i, 31) {
    int rem = n - cnt[i];
    if (rem > 0 && rem <= k) {
      cnt[i] += rem;
      k -= rem;
    }
  }
  reverse(cnt.begin(), cnt.end());
  int ans = 0;
  rep(i, 31) {
    if (cnt[i] == n) ans |= (1 << i);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}