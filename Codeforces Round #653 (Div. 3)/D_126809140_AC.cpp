/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1374/submission/126809140
 * Submitted at: 2021-08-24 15:06:07
 * Problem URL: https://codeforces.com/contest/1374/problem/D
 * Result: AC
 * Execution Time: 499 ms
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
  ll n, k;
  cin >> n >> k;
  map<ll, ll> rem;
  ll maxim = 0, maximI = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    ll remain = (k - (a % k)) % k;
    rem[remain]++;
    if (maxim <= rem[remain] && remain != 0) {
      if (maxim == rem[remain]) {
        maximI = max(maximI, remain);
      }
      else {
        maximI = remain;
      }
      maxim = rem[remain];
    }
  }
  if (rem[0] == n) {
    cout << 0 << endl;
    return;
  }

  ll ans = (maxim * k) - (k - maximI) + 1;
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