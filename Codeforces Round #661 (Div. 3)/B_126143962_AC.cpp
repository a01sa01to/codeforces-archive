/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1399/submission/126143962
 * Submitted at: 2021-08-17 14:27:07
 * Problem URL: https://codeforces.com/contest/1399/problem/B
 * Result: AC
 * Execution Time: 61 ms
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
  ll1d a(n), b(n);
  ll mina = 1e9, minb = 1e9;
  rep(i, n) {
    cin >> a[i];
    mina = min(mina, a[i]);
  }
  rep(i, n) {
    cin >> b[i];
    minb = min(minb, b[i]);
  }
  ll ans = 0;
  rep(i, n) {
    ll ca = a[i] - mina;
    ll cb = b[i] - minb;
    ans += max(ca, cb);
  }
  cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    solve();
  }
  return 0;
}