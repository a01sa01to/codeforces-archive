/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154801850
 * Submitted at: 2022-04-24 11:26:21
 * Problem URL: https://codeforces.com/contest/1669/problem/C
 * Result: AC
 * Execution Time: 0 ms
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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  {
    int p = a[0] % 2;
    for (int i = 0; i < n; i += 2) {
      if (a[i] % 2 != p) {
        cout << "No" << endl;
        return;
      }
    }
  }
  {
    int p = a[1] % 2;
    for (int i = 1; i < n; i += 2) {
      if (a[i] % 2 != p) {
        cout << "No" << endl;
        return;
      }
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