/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1311/submission/127494108
 * Submitted at: 2021-08-31 14:19:27
 * Problem URL: https://codeforces.com/contest/1311/problem/C
 * Result: AC
 * Execution Time: 374 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  ll2d pos(n, ll1d(26, 0));
  ll1d tmp(26, 0), ans(26, 0);
  rep(i, n) {
    tmp[s[i] - 'a']++;
    pos[i] = tmp;
  }
  rep(i, m) {
    int p;
    cin >> p;
    p--;
    ll1d sum = pos[p];
    rep(j, 26) {
      ans[j] += sum[j];
    }
  }
  rep(i, 26) {
    cout << ans[i] + pos[n - 1][i] << " ";
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}