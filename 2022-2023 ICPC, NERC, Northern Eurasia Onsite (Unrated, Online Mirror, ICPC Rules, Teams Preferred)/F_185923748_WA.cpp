/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1773/submission/185923748
 * Submitted at: 2022-12-19 17:17:09
 * Problem URL: https://codeforces.com/contest/1773/problem/F
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
 inline bool q(char x) { return x == '?'; }
 void solve() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = s.size();
  if (n % 2 == 1) {
    if (q(s[n / 2])) {
      s[n / 2] = (a % 2 == 1 ? '0' : '1');
      (s[n / 2] == '0' ? a : b)--;
    }
    else if (s[n / 2] == '0' && a % 2 == 1) {
      a--;
    }
    else if (s[n / 2] == '1' && b % 2 == 1) {
      b--;
    }
    else {
      cout << -1 << endl;
      return;
    }
  }
  if (a % 2 == 1 || b % 2 == 1) {
    cout << -1 << endl;
    return;
  }
  rep(i, n / 2) {
    if (!q(s[i]) && !q(s[n - i - 1]) && s[i] != s[n - i - 1]) {
      cout << -1 << endl;
      return;
    }
    if (q(s[i]) && q(s[n - i - 1])) continue;
    if (q(s[i]) && !q(s[n - i - 1])) s[i] = s[n - i - 1];
    if (!q(s[i]) && q(s[n - i - 1])) s[n - i - 1] = s[i];
    (s[i] == '0' ? a : b) -= 2;
  }
  if (a < 0 || b < 0) {
    cout << -1 << endl;
    return;
  }
  rep(i, n / 2) {
    if (q(s[i])) {
      if (a >= 2) {
        s[i] = s[n - i - 1] = '0';
        a -= 2;
      }
      else {
        s[i] = s[n - i - 1] = '1';
        b -= 2;
      }
    }
  }
  cout << s << endl;
  return;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}