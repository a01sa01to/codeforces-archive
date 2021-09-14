/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1213/submission/128782027
 * Submitted at: 2021-09-14 13:15:51
 * Problem URL: https://codeforces.com/contest/1213/problem/B
 * Result: AC
 * Execution Time: 218 ms
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
  int n;
  cin >> n;
  ll1d a(n);
  rep(i, n) cin >> a[i];
  int minim = a[n - 1];
  int ans = 0;
  rep(i, n) {
    if (a[n - i - 1] > minim) {
      ans++;
    }
    else {
      minim = a[n - i - 1];
    }
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