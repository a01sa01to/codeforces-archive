/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1741/submission/175766221
 * Submitted at: 2022-10-12 22:32:27
 * Problem URL: https://codeforces.com/contest/1741/problem/C
 * Result: AC
 * Execution Time: 15 ms
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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> sum(n + 1, 0);
  rep(i, n) sum[i + 1] = sum[i] + a[i];
  int ans = 1e9;
  Debug(sum);
  rep(i, n + 1) {
    int s = sum[i];
    int idx = i;
    int t = i;
    for (int j = idx; j <= n; j++) {
      int tmp = sum[j] - sum[idx];
      Debug(s, t, tmp, i, j);
      if (tmp == s) {
        t = max(t, j - idx);
        idx = j;
      }
      else if (tmp > s) {
        break;
      }
    }
    if (idx != n) t = 1e9;
    Debug(t);
    ans = min(ans, t);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}