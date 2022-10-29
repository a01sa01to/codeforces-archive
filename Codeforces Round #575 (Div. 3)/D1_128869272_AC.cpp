/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1196/submission/128869272
 * Submitted at: 2021-09-15 13:52:04
 * Problem URL: https://codeforces.com/contest/1196/problem/D1
 * Result: AC
 * Execution Time: 30 ms
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
  string s;
  cin >> s;
  int ans = 1e4;
  const string rgb = "RGB";
  rep(i, n - k + 1) rep(j, 3) {
    int cnt = 0;
    rep(ii, k) {
      if (s[i + ii] != rgb[(j + ii) % 3]) cnt++;
    }
    ans = min(ans, cnt);
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