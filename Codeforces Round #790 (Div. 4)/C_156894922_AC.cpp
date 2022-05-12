/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156894922
 * Submitted at: 2022-05-12 16:37:31
 * Problem URL: https://codeforces.com/contest/1676/problem/C
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
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  int ans = 1e9;
  rep(i, n) rep(j, n) {
    if(i >= j) continue;
    int cnt = 0;
    rep(k, m) {
      cnt += abs(s[i][k] - s[j][k]);
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}