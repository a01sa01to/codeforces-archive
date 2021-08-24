/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1374/submission/126812598
 * Submitted at: 2021-08-24 15:53:43
 * Problem URL: https://codeforces.com/contest/1374/problem/E1
 * Result: AC
 * Execution Time: 467 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef tuple<ll, bool, bool> TP;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  cout << fixed << setprecision(15);
  ll n, k;
  cin >> n >> k;
  ll alice = 0, bob = 0;
  ll2d book(3);
  ll2d sum(3);
  rep(i, n) {
    ll time, a, b;
    cin >> time >> a >> b;
    if (a) alice++;
    if (b) bob++;
    if (a || b) {
      book[2 * a + b - 1].push_back(time);
    }
  }
  if (alice < k || bob < k) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 1e10;
  rep(i, 3) {
    sort(all(book[i]));
    sum[i].push_back(0);
    rep(j, book[i].size()) {
      sum[i].push_back(sum[i][j] + book[i][j]);
    }
  }
  rep(c, min(ll(book[2].size()), k) + 1) {
    // 両方好きな方からc冊、のこりk-c冊
    if (k - c <= book[0].size() && k - c <= book[1].size()) {
      ans = min(ans, sum[2][c] + sum[1][k - c] + sum[0][k - c]);
    }
  }
  cout << ans << endl;
  return 0;
}