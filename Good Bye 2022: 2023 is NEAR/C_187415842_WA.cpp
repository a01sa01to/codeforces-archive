/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1770/submission/187415842
 * Submitted at: 2022-12-31 15:55:08
 * Problem URL: https://codeforces.com/contest/1770/problem/C
 * Result: WA
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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      cout << "No" << endl;
      return;
    }
  }
  for (int i = 2; i <= n / 2; i++) {
    vector<int> cnt(i, 0);
    rep(j, n) cnt[a[j] % i]++;
    bool ok = true;
    rep(j, i) {
      if (cnt[j] > 1) ok = false;
    }
    Debug(i, cnt, ok);
    if (!ok) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}