/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1556/submission/127343644
 * Submitted at: 2021-08-29 23:47:35
 * Problem URL: https://codeforces.com/contest/1556/problem/A
 * Result: AC
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  ll c, d;
  cin >> c >> d;
  if (c == 0 && d == 0) {
    cout << 0 << endl;
  }
  else if (c % 2 == d % 2) {
    if (c == d) {
      cout << 1 << endl;
    }
    else {
      cout << 2 << endl;
    }
  }
  else {
    cout << -1 << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}