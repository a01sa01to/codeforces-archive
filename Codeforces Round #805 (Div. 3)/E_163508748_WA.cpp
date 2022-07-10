/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1702/submission/163508748
 * Submitted at: 2022-07-11 00:06:06
 * Problem URL: https://codeforces.com/contest/1702/problem/E
 * Result: WA
 * Execution Time: 93 ms
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
  set<int> s, t;
  bool output = false;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if (output) continue;
    if (a == b) {
      cout << "NO" << endl;
      output = true;
    }
    else if (!s.count(a) && !s.count(b)) {
      s.insert(a), s.insert(b);
    }
    else if (!t.count(a) && !t.count(b)) {
      t.insert(a), t.insert(b);
    }
    else {
      cout << "NO" << endl;
      output = true;
    }
  }
  if (!output) cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}