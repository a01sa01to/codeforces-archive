/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1579/submission/130101784
 * Submitted at: 2021-09-28 23:38:48
 * Problem URL: https://codeforces.com/contest/1579/problem/A
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0;
  rep(i, s.size()) {
    if (s[i] == 'A') a++;
    if (s[i] == 'B') b++;
    if (s[i] == 'C') c++;
  }
  if (a + c == b) cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}