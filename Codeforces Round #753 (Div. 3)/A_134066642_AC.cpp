/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1607/submission/134066642
 * Submitted at: 2021-11-02 23:39:53
 * Problem URL: https://codeforces.com/contest/1607/problem/A
 * Result: AC
 * Execution Time: 0 ms
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
  string s, t;
  cin >> s >> t;
  int prev = -1, ans = 0;
  rep(i, t.size()) {
    rep(j, s.size()) {
      if (t[i] == s[j]) {
        if (prev != -1) ans += abs(prev - j);
        prev = j;
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