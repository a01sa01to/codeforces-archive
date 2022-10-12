/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1741/submission/175762631
 * Submitted at: 2022-10-12 22:05:10
 * Problem URL: https://codeforces.com/contest/1741/problem/B
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
  if (n == 3) {
    cout << -1 << endl;
    return;
  }
  vector<int> ans = { n, n - 1 };
  for (int i = 1; i <= n - 2; i++) {
    ans.push_back(i);
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}