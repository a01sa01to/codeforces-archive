/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154802044
 * Submitted at: 2022-04-24 11:31:01
 * Problem URL: https://codeforces.com/contest/1669/problem/D
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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<string> v(0);
  {
    string tmp = "";
    rep(i, n) {
      if (s[i] == 'W') {
        if (tmp != "") v.push_back(tmp);
        tmp = "";
      }
      else {
        tmp += s[i];
      }
    }
    if (tmp != "") v.push_back(tmp);
  }
  rep(i, v.size()) {
    bool b = false, r = false;
    rep(j, v[i].size()) {
      if (v[i][j] == 'B') b = true;
      if (v[i][j] == 'R') r = true;
    }
    if (!b || !r) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}