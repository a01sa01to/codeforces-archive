/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1183/submission/128952371
 * Submitted at: 2021-09-16 13:20:12
 * Problem URL: https://codeforces.com/contest/1183/problem/B
 * Result: AC
 * Execution Time: 46 ms
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
  int n, k;
  cin >> n >> k;
  ll1d a(n);
  ll maxim = 1e10, minim = 0;
  rep(i, n) {
    cin >> a[i];
    // | ai - bi | <= k
    // -k <= ai-bi <= k
    // -k <= ai - bi, ai-bi <= k
    // ai-k <= bi <= ai+k
    maxim = min(maxim, k + a[i]);
    minim = max(minim, a[i] - k);
  }
  if (minim > maxim) cout << -1 << endl;
  else
    cout << maxim << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}