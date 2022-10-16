/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1744/submission/176514107
 * Submitted at: 2022-10-16 23:48:55
 * Problem URL: https://codeforces.com/contest/1744/problem/C
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
  char c;
  cin >> c;
  string s;
  cin >> s;
  vector<int> green(0);
  rep(i, 2 * n) {
    if (s[i % n] == 'g') green.push_back(i);
  }
  int ans = 0;
  rep(i, n) {
    if (s[i] == c) {
      int j = *lower_bound(green.begin(), green.end(), i);
      ans = max(ans, j - i);
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}