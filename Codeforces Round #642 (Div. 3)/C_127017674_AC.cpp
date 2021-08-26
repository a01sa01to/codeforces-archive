/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1353/submission/127017674
 * Submitted at: 2021-08-26 14:04:08
 * Problem URL: https://codeforces.com/contest/1353/problem/C
 * Result: AC
 * Execution Time: 30 ms
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
  ll n;
  cin >> n;
  ll ans = 0;
  rep(i, n / 2 + 1) {
    ans += i * i * 8;
  }
  cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}