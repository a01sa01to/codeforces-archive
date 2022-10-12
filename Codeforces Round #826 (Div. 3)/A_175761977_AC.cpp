/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1741/submission/175761977
 * Submitted at: 2022-10-12 22:00:18
 * Problem URL: https://codeforces.com/contest/1741/problem/A
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
  string s, t;
  cin >> s >> t;
  int a, b;
  if (s == "M") a = 0;
  else {
    a = (s.back() == 'S' ? -1 : 1) * s.size();
  }
  if (t == "M") b = 0;
  else {
    b = (t.back() == 'S' ? -1 : 1) * t.size();
  }
  Debug(a, b);
  if (a == b)
    cout << "=" << endl;
  else if (a < b)
    cout << "<" << endl;
  else
    cout << ">" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}