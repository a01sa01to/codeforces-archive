/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1311/submission/127493564
 * Submitted at: 2021-08-31 14:07:46
 * Problem URL: https://codeforces.com/contest/1311/problem/B
 * Result: AC
 * Execution Time: 31 ms
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
  int m, n;
  cin >> n >> m;
  vector<P> a(n);
  set<int> p;
  rep(i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }
  rep(i, m) {
    int _;
    cin >> _;
    p.insert(--_);
  }
  sort(all(a));
  for (int i = n - 1; i > 0; i--) {
    ll ais = a[i].second;
    // cout << "[DEB] " << i << " " << ais << " | " << a[i].first << endl;
    if (ais < i) {
      for (ll j = ais; j < i; j++) {
        // cout << "[DEB2] " << j << " " << p.count(j) << endl;
        if (!p.count(j)) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
  return;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}