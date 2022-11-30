/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1551/submission/183322324
 * Submitted at: 2022-11-30 16:20:05
 * Problem URL: https://codeforces.com/contest/1551/problem/B2
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  map<int, vector<int>> mp;
  rep(i, n) {
    if (mp[a[i]].size() < k) mp[a[i]].push_back(i);
  }
  int shouldPaint = 0;
  for (auto [_, v] : mp) shouldPaint += v.size();
  shouldPaint = (shouldPaint / k) * k;
  vector<int> ans(n, 0);
  int cur = 0;
  for (auto [_, v] : mp) {
    for (int i : v) {
      ans[i] = cur + 1;
      cur++;
      cur %= k;
      shouldPaint--;
      if (shouldPaint <= 0) break;
    }
    if (shouldPaint <= 0) break;
  }
  rep(i, n) cout << ans[i] << " ";
  cout << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}