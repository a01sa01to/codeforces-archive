/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1196/submission/128868690
 * Submitted at: 2021-09-15 13:39:51
 * Problem URL: https://codeforces.com/contest/1196/problem/C
 * Result: AC
 * Execution Time: 810 ms
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
  vector<pair<P, P>> canMove(n);
  rep(i, n) {
    int x, y, f1, f2, f3, f4;
    cin >> x >> y >> f1 >> f2 >> f3 >> f4;
    pair<P, P> tmp = { { x, y }, { x, y } };
    if (f1 == 1) tmp.first.first = -1e5;
    if (f2 == 1) tmp.second.second = 1e5;
    if (f3 == 1) tmp.second.first = 1e5;
    if (f4 == 1) tmp.first.second = -1e5;
    canMove[i] = tmp;
  }
  pair<P, P> ans = { { -1e5, -1e5 }, { 1e5, 1e5 } };
  rep(i, n) {
    pair<P, P> tmp = canMove[i];
    ans.first.first = max(ans.first.first, tmp.first.first);
    ans.first.second = max(ans.first.second, tmp.first.second);
    ans.second.first = min(ans.second.first, tmp.second.first);
    ans.second.second = min(ans.second.second, tmp.second.second);
  }
  if (ans.first.first > ans.second.first || ans.first.second > ans.second.second) {
    cout << 0 << endl;
    return;
  }
  cout << 1 << " " << ans.first.first << " " << ans.first.second << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}