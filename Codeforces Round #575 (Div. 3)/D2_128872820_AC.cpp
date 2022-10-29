/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1196/submission/128872820
 * Submitted at: 2021-09-15 15:00:44
 * Problem URL: https://codeforces.com/contest/1196/problem/D2
 * Result: AC
 * Execution Time: 873 ms
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
typedef tuple<ll, ll, ll> TP;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 1e6;
  const string rgb = "RGB";
  rep(j, 3) {
    vector<bool> different(n);
    int cnt = 0;
    rep(i, n) {
      different[i] = (s[i] != rgb[(j + i) % 3]);
      if (different[i]) cnt++;
      if (i >= k) {
        if (different[i - k]) {
          cnt--;
        }
        ans = min(ans, cnt);
      }
      else if (i == k - 1) {
        ans = min(ans, cnt);
      }
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