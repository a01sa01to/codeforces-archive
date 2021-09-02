/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1249/submission/127666422
 * Submitted at: 2021-09-02 15:12:45
 * Problem URL: https://codeforces.com/contest/1249/problem/D1
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
  vector<P> seg(n);
  vector<bool> seg_rem(n, false);
  int ans = 0;
  ll1d cnt(200);
  rep(i, n) {
    cin >> seg[i].first >> seg[i].second;
    cnt[--seg[i].first]++;
    cnt[--seg[i].second + 1]--;
  }
  rep(i, 200 - 1) cnt[i + 1] += cnt[i];
  rep(i, 200) {
    while (cnt[i] > k) {
      int prev = -1;
      rep(j, n) {
        if (!seg_rem[j] && (seg[j].first <= i && i <= seg[j].second) && (prev == -1 || seg[j].second > seg[prev].second)) {
          prev = j;
        }
      }
      for (int j = seg[prev].first; j <= seg[prev].second; j++) cnt[j]--;
      seg_rem[prev] = true;
      ans++;
    }
  }
  cout << ans << endl;
  rep(i, n) {
    if (seg_rem[i]) cout << i + 1 << " ";
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while (t--) solve();
  solve();
  return 0;
}