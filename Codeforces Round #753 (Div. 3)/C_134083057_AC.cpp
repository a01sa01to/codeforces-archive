/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1607/submission/134083057
 * Submitted at: 2021-11-03 00:04:31
 * Problem URL: https://codeforces.com/contest/1607/problem/C
 * Result: AC
 * Execution Time: 436 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int n;
  cin >> n;
  ll1d v(n);
  rep(i, n) cin >> v[i];
  sort(all(v));
  ll maxim = v[0];
  rep(i, n - 1) {
    maxim = max(maxim, v[i + 1] - v[i]);
  }
  cout << maxim << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}