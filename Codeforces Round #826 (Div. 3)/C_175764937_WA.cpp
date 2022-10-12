/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1741/submission/175764937
 * Submitted at: 2022-10-12 22:22:34
 * Problem URL: https://codeforces.com/contest/1741/problem/C
 * Result: WA
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
  int ans = n;
  Debug(sum);
  rep(i, n - 1) {
    int ansT = i + 1;
    bool flg = false;
    int s = sum[i + 1];
    int t = s;
    int nw = i + 1;
    Debug("---");
    while (true) {
      Debug(ansT, flg, s, t, nw);
      auto itr1 = lower_bound(sum.begin() + nw, sum.end(), s + t);
      auto itr2 = upper_bound(sum.begin() + nw, sum.end(), s + t);
      if (itr1 == sum.end() && nw == n) break;
      if (itr1 == sum.end() || itr1 == itr2) {
        flg = true;
        break;
      }
      int idx = itr1 - sum.begin();
      ansT = max(ansT, idx - nw);
      nw = idx;
      t = sum[nw];
    }
    if (!flg) ans = min(ans, ansT);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}