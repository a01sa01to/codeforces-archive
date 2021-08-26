/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1353/submission/127017221
 * Submitted at: 2021-08-26 13:54:07
 * Problem URL: https://codeforces.com/contest/1353/problem/B
 * Result: AC
 * Execution Time: 15 ms
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
  int n, k;
  cin >> n >> k;
  ll1d a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  sort(all(a));
  sort(all(b), greater<ll>());
  rep(i, k) {
    if (a[i] < b[i]) {
      swap(a[i], b[i]);
    }
  }
  ll sum = 0;
  rep(i, n) sum += a[i];
  cout << sum << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}