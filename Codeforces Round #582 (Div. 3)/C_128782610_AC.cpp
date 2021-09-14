/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1213/submission/128782610
 * Submitted at: 2021-09-14 13:26:32
 * Problem URL: https://codeforces.com/contest/1213/problem/C
 * Result: AC
 * Execution Time: 31 ms
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  ll n, m;
  cin >> n >> m;
  ll cnt = n / m;
  vector<int> lastDigit(10);
  rep(i, 10) lastDigit[i] = (m * (i + 1)) % 10;
  ll ans = 0;
  rep(i, 10) {
    ans += (cnt / 10) * lastDigit[i];
  }
  rep(i, cnt % 10) {
    ans += lastDigit[i];
  }
  cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}