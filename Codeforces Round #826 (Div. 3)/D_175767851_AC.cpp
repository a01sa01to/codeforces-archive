/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1741/submission/175767851
 * Submitted at: 2022-10-12 22:42:58
 * Problem URL: https://codeforces.com/contest/1741/problem/D
 * Result: AC
 * Execution Time: 312 ms
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
  int ans = 0;
  Debug(a);
  for (int b = 1; b <= n; b *= 2) {
    for (int i = 0; i + b < n; i += b * 2) {
      if (abs(a[i] - a[i + b]) != b) {
        cout << -1 << endl;
        return;
      }
      if (a[i] > a[i + b]) {
        ans++;
        swap(a[i], a[i + b]);
      }
    }
    Debug(a);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}