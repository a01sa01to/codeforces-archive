/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1702/submission/163479715
 * Submitted at: 2022-07-10 23:42:48
 * Problem URL: https://codeforces.com/contest/1702/problem/B
 * Result: AC
 * Execution Time: 31 ms
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
  string s;
  cin >> s;
  int ans = 1;
  set<int> st;
  rep(i, s.size()) {
    st.insert(s[i]);
    if (st.size() > 3) {
      ans++;
      st.clear();
      st.insert(s[i]);
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}