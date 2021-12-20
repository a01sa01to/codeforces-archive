/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1619/submission/140024064
 * Submitted at: 2021-12-20 23:40:22
 * Problem URL: https://codeforces.com/contest/1619/problem/B
 * Result: AC
 * Execution Time: 93 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  set<int> s;
  for (int i = 1; i * i <= n; ++i) s.insert(i * i);
  for (int i = 1; i * i * i <= n; ++i) s.insert(i * i * i);
  cout << s.size() << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}