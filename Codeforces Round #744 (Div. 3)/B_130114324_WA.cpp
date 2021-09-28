/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1579/submission/130114324
 * Submitted at: 2021-09-28 23:50:12
 * Problem URL: https://codeforces.com/contest/1579/problem/B
 * Result: WA
 * Execution Time: 155 ms
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
  ll1d ans(0);
  for (int i = n - 1; i > 0; i--)
    for (int j = 0; j < i; j++) {
      if (a[j] > a[j + 1]) {
        ans.push_back(j);
        swap(a[j], a[j + 1]);
      }
    }
  cout << ans.size() << endl;
  for (ll x : ans) printf("%lld %lld 1\n", x + 1, x + 2);
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}