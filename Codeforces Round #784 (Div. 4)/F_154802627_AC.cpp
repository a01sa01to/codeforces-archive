/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154802627
 * Submitted at: 2022-04-24 11:44:38
 * Problem URL: https://codeforces.com/contest/1669/problem/F
 * Result: AC
 * Execution Time: 264 ms
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
  vector<int> sum(n + 1, 0);
  rep(i, n) {
    int a;
    cin >> a;
    sum[i + 1] = sum[i] + a;
  }
  int ans = 0;
  rep(i, n) {
    // bob
    int b = sum[n] - sum[i];
    // alice
    auto l = lower_bound(sum.begin(), sum.end(), b);
    auto r = upper_bound(sum.begin(), sum.end(), b);
    int aidx = l - sum.begin();
    if (r - l == 1 && aidx <= i) {
      Debug(sum[n] - sum[i], aidx);
      ans = max(ans, n - i + aidx);
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