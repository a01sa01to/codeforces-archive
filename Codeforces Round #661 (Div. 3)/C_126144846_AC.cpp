/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1399/submission/126144846
 * Submitted at: 2021-08-17 14:42:29
 * Problem URL: https://codeforces.com/contest/1399/problem/C
 * Result: AC
 * Execution Time: 498 ms
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
  int n;
  cin >> n;
  ll1d w(n);
  rep(i, n) cin >> w[i];
  ll ans = 0;
  rep(s, 2 * n) {
    ll tmpa = 0;
    set<ll> used;
    rep(i, n) {
      for (ll j = i + 1; j < n; j++) {
        if (s + 1 == w[i] + w[j] && !used.count(i) && !used.count(j)) {
          tmpa++;
          used.insert(i);
          used.insert(j);
        }
      }
    }
    ans = max(ans, tmpa);
  }
  cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    solve();
  }
  return 0;
}