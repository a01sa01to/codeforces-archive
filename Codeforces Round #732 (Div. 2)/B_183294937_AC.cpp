/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1546/submission/183294937
 * Submitted at: 2022-11-30 12:23:57
 * Problem URL: https://codeforces.com/contest/1546/problem/B
 * Result: AC
 * Execution Time: 62 ms
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
  int n, m;
  cin >> n >> m;
  vector cnt1(m, vector<int>(26, 0));
  vector cnt2(m, vector<int>(26, 0));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, m) cnt1[j][s[j] - 'a']++;
  }
  rep(i, n - 1) {
    string s;
    cin >> s;
    rep(j, m) cnt2[j][s[j] - 'a']++;
  }
  rep(i, m) {
    rep(j, 26) {
      if (cnt1[i][j] != cnt2[i][j]) {
        cout << (char) ('a' + j);
        break;
      }
    }
  }
  cout << endl;
  return;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}