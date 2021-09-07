/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1234/submission/128095311
 * Submitted at: 2021-09-07 14:11:53
 * Problem URL: https://codeforces.com/contest/1234/problem/D
 * Result: TLE
 * Execution Time: 2000 ms
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
  string s;
  cin >> s;
  ll2d sum(s.size() + 1, ll1d(26, 0));
  rep(i, s.size()) {
    rep(j, 26) {
      sum[i + 1][j] = sum[i][j] + (s[i] == 'a' + j);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      char prev = s[pos - 1];
      for (int i = pos; i <= s.size(); i++) {
        sum[i][prev - 'a']--;
        sum[i][c - 'a']++;
      }
      swap(s[pos - 1], c);
    }
    else {
      int l, r;
      cin >> l >> r;
      // cout << "[DEB] " << s << endl;
      int ans = 0;
      rep(i, 26) {
        // cout << "[DEB1] " << char(i + 'a') << ": " << sum[r][i] << " " << sum[l - 1][i] << endl;
        ans += (sum[r][i] > sum[l - 1][i]);
      }
      cout << ans << endl;
    }
  }
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while (t--) solve();
  solve();
  return 0;
}