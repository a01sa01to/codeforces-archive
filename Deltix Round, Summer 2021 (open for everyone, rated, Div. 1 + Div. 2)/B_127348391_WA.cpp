/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1556/submission/127348391
 * Submitted at: 2021-08-29 23:56:08
 * Problem URL: https://codeforces.com/contest/1556/problem/B
 * Result: WA
 * Execution Time: 155 ms
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
  int n;
  cin >> n;
  ll1d a(n);
  ll odd = 0, even = 0, ans = 0;
  rep(i, n) {
    cin >> a[i];
    if (a[i] % 2 == 1) {
      odd++;
      if (even > odd) {
        ans += even - odd;
      }
    }
    else {
      even++;
      if (odd > even) {
        ans += odd - even;
      }
    }
  }
  if (abs(odd - even) > 1) {
    cout << -1 << endl;
    return;
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