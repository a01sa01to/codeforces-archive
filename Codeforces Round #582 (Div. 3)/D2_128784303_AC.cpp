/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1213/submission/128784303
 * Submitted at: 2021-09-14 13:58:58
 * Problem URL: https://codeforces.com/contest/1213/problem/D2
 * Result: AC
 * Execution Time: 498 ms
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
  vector<priority_queue<ll, vector<ll>, greater<ll>>> cnt(2e5 + 1);
  rep(i, n) {
    int a;
    cin >> a;
    int times = 0;
    while (a > 0) {
      cnt[a].push(times++);
      a /= 2;
    }
    cnt[0].push(times);
  }
  int ans = 4e10;
  rep(i, 2e5 + 1) {
    if (cnt[i].size() >= k) {
      int tmp = 0;
      rep(_, k) {
        int tp = cnt[i].top();
        cnt[i].pop();
        tmp += tp;
      }
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while (t--) solve();
  solve();
  return 0;
}