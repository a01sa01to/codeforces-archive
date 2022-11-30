/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1551/submission/183320070
 * Submitted at: 2022-11-30 15:56:21
 * Problem URL: https://codeforces.com/contest/1551/problem/B1
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
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
 void solve() {
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  rep(i, s.size()) cnt[s[i] - 'a']++;
  int ans = 0;
  int odd = 0;
  rep(i, 26) {
    if (cnt[i] >= 2) ans++;
    if (cnt[i] == 1) odd++;
  }
  ans += odd / 2;
  cout << ans << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}