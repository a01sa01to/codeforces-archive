/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1538/submission/125442982
 * Submitted at: 2021-08-10 14:04:56
 * Problem URL: https://codeforces.com/contest/1538/problem/C
 * Result: AC
 * Execution Time: 420 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    ll n, l, r;
    cin >> n >> l >> r;
    ll1d a(n);
    rep(i, n) { cin >> a[i]; }
    sort(all(a));
    ll ans = 0;
    rep(i, n - 1) {
      ll l_ok = i, l_ng = n;
      while (abs(l_ok - l_ng) > 1) {
        ll mid = (l_ok + l_ng) / 2;
        if (a[i] + a[mid] < l) { l_ok = mid; }
        else {
          l_ng = mid;
        }
      }
      ll r_ok = i, r_ng = n;
      while (abs(r_ok - r_ng) > 1) {
        ll mid = (r_ok + r_ng) / 2;
        if (a[i] + a[mid] <= r) { r_ok = mid; }
        else {
          r_ng = mid;
        }
      }
      ans += max(0LL, r_ok - l_ok);
    }
    cout << ans << endl;
  }
  return 0;
}