/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1770/submission/187416423
 * Submitted at: 2022-12-31 16:01:07
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
 bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return x != 1;
}
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
    if (!isPrime(i)) continue;
    vector<int> cnt(i, 0);
    rep(j, n) cnt[a[j] % i]++;
    if (*min_element(cnt.begin(), cnt.end()) > 1) {
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