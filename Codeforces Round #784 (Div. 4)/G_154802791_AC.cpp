/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154802791
 * Submitted at: 2022-04-24 11:48:11
 * Problem URL: https://codeforces.com/contest/1669/problem/G
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
  int h, w;
  cin >> h >> w;
  vector<string> Grid(h);
  rep(i, h) cin >> Grid[i];
  while (true) {
    bool changed = false;
    rep(i, h - 1) rep(j, w) {
      if (Grid[i][j] == '*' && Grid[i + 1][j] == '.') {
        swap(Grid[i][j], Grid[i + 1][j]);
        changed = true;
      }
    }
    if (!changed) break;
  }
  rep(i, h) cout << Grid[i] << endl;
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}