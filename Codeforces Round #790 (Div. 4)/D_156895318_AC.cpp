/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156895318
 * Submitted at: 2022-05-12 16:42:56
 * Problem URL: https://codeforces.com/contest/1676/problem/D
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
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n, m;
  cin >> n >> m;
  vector Grid(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> Grid[i][j];

  int ans = 0;
  rep(i, n) rep(j, m) {
    int cnt = Grid[i][j];
    for (int k = 1; k <= min(i, j); ++k) {
      cnt += Grid[i - k][j - k];
    }
    for (int k = 1; k <= min(i, m - j - 1); ++k) {
      cnt += Grid[i - k][j + k];
    }
    for (int k = 1; k <= min(n - i - 1, j); ++k) {
      cnt += Grid[i + k][j - k];
    }
    for (int k = 1; k <= min(n - i - 1, m - j - 1); ++k) {
      cnt += Grid[i + k][j + k];
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}