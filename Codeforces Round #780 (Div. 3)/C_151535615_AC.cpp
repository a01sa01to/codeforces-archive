/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1660/submission/151535615
 * Submitted at: 2022-03-31 23:59:33
 * Problem URL: https://codeforces.com/contest/1660/problem/C
 * Result: AC
 * Execution Time: 61 ms
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
  string a;
  cin >> a;
  int ans = 0;
  vector<int> cnt(26, 0);
  rep(i, a.size()) {
    ++cnt[a[i] - 'a'];
    if (cnt[a[i] - 'a'] == 2) {
      ans += accumulate(cnt.begin(), cnt.end(), -2);
      cnt.assign(26, 0);
    }
  }
  ans += accumulate(cnt.begin(), cnt.end(), 0);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}