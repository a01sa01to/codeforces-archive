/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1702/submission/163544440
 * Submitted at: 2022-07-11 00:51:12
 * Problem URL: https://codeforces.com/contest/1702/problem/F
 * Result: WA
 * Execution Time: 108 ms
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
  multiset<int> a, b;
  rep(i, n) {
    int t;
    cin >> t;
    t /= (t & -t);
    a.insert(t);
  }
  rep(i, n) {
    int t;
    cin >> t;
    t /= (t & -t);
    if (a.find(t) != a.end()) {
      a.erase(a.find(t));
    }
    else {
      b.insert(t);
    }
  }
  Debug(a, b);
  while (!a.empty() && !b.empty()) {
    int x = *b.begin();
    if (x == 0) {
      b.erase(b.begin());
    }
    else if (a.find(x) != a.end()) {
      a.erase(a.find(x));
      b.erase(b.find(x));
    }
    else {
      b.erase(x);
      b.insert(x >> 1);
    }
    Debug(a, b);
  }
  cout << (a.empty() ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}