/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156895647
 * Submitted at: 2022-05-12 16:47:35
 * Problem URL: https://codeforces.com/contest/1676/problem/E
 * Result: AC
 * Execution Time: 857 ms
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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  vector<int> sum(n + 1, 0);
  rep(i, n) sum[i + 1] = sum[i] + a[i];

  while (q--) {
    int x;
    cin >> x;
    if (x > sum[n]) {
      cout << -1 << endl;
    }
    else {
      auto itr = lower_bound(sum.begin(), sum.end(), x);
      cout << itr - sum.begin() << endl;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}