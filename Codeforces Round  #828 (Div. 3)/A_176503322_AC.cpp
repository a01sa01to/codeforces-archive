/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1744/submission/176503322
 * Submitted at: 2022-10-16 23:37:35
 * Problem URL: https://codeforces.com/contest/1744/problem/A
 * Result: AC
 * Execution Time: 46 ms
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
  string s;
  cin >> s;
  map<int, int> mp;
  rep(i, n) {
    if (mp.count(a[i])) {
      if (s[i] != mp[a[i]]) {
        cout << "NO" << endl;
        return;
      }
    }
    else {
      mp[a[i]] = s[i];
    }
  }
  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}