/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1660/submission/151565893
 * Submitted at: 2022-04-01 00:53:10
 * Problem URL: https://codeforces.com/contest/1660/problem/F1
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
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> sum(n + 1, 0);
  rep(i, n) sum[i + 1] = sum[i] + (s[i] == '+') * 2 - 1;
  Debug(sum);
  int ans = 0;
  rep(i, n) rep(j, n) {
    if (j < i) continue;
    if (sum[j + 1] - sum[i] == 0) ++ans;
    if ((sum[j + 1] - sum[i]) < 0 && (sum[j + 1] - sum[i]) % 3 == 0) ++ans;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}