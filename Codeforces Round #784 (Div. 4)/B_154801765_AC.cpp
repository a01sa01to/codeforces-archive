/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154801765
 * Submitted at: 2022-04-24 11:23:59
 * Problem URL: https://codeforces.com/contest/1669/problem/B
 * Result: AC
 * Execution Time: 296 ms
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
  map<int, int> cnt;
  rep(i, n) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  for (auto [key, val] : cnt) {
    if (val >= 3) {
      cout << key << endl;
      return;
    }
  }
  cout << -1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}