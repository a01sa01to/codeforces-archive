/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1183/submission/128954216
 * Submitted at: 2021-09-16 14:03:27
 * Problem URL: https://codeforces.com/contest/1183/problem/D
 * Result: AC
 * Execution Time: 748 ms
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
  ll1d cnt(n);
  rep(i, n) {
    int a;
    cin >> a;
    cnt[--a]++;
  }
  sort(all(cnt), greater<ll>());
  ll ans = cnt[0];
  rep(i, n) {
    if (i != 0) {
      if (cnt[i - 1] <= 1) {
        break;
      }
      else if (cnt[i] >= cnt[i - 1]) {
        cnt[i] = cnt[i - 1] - 1;
      }
      ans += cnt[i];
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