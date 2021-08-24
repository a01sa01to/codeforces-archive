/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1374/submission/126804568
 * Submitted at: 2021-08-24 13:55:27
 * Problem URL: https://codeforces.com/contest/1374/problem/A
 * Result: AC
 * Execution Time: 389 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  ll x, y, n;
  cin >> x >> y >> n;
  ll ans = y % x;
  ans += ((n - ans) / x) * x;
  cout << ans << endl;
  return;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}