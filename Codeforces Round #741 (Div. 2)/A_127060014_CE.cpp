/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1562/submission/127060014
 * Submitted at: 2021-08-26 23:40:37
 * Problem URL: https://codeforces.com/contest/1562/problem/A
 * Result: CE
 * Execution Time: 0 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  ll l, r;
  cin >> l >> r;
  ll a = r, b = max(l, r / 2 + 1);
  cout << a % b << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}