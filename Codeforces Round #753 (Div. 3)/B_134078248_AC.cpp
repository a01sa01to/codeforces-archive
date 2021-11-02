/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1607/submission/134078248
 * Submitted at: 2021-11-02 23:56:00
 * Problem URL: https://codeforces.com/contest/1607/problem/B
 * Result: AC
 * Execution Time: 93 ms
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
  ll x, n;
  cin >> x >> n;
  switch (n % 4) {
    case 0:
      break;
    case 1:
      x += (x & 1 ? n : -n);
      break;
    case 2:
      x += (x & 1 ? -1 : 1);
      break;
    case 3:
      x += (x & 1 ? -n - 1 : n + 1);
      break;
  }
  cout << x << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}