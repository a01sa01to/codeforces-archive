/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1196/submission/128868034
 * Submitted at: 2021-09-15 13:26:13
 * Problem URL: https://codeforces.com/contest/1196/problem/B
 * Result: AC
 * Execution Time: 1668 ms
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
  int odd = 0;
  rep(i, n) {
    cin >> a[i];
    if (a[i] % 2 == 1) odd++;
  }
  if (odd < k) {
    cout << "NO" << endl;
    return;
  }
  else if ((odd - k) % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  int output = 0;
  rep(i, n) {
    if (output + 1 == k) break;
    if (a[i] % 2 == 1) {
      output++;
      cout << i + 1 << " ";
    }
  }
  cout << n << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}