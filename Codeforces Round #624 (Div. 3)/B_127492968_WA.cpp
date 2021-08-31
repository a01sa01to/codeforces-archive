/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1311/submission/127492968
 * Submitted at: 2021-08-31 13:54:14
 * Problem URL: https://codeforces.com/contest/1311/problem/B
 * Result: WA
 * Execution Time: 15 ms
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
  ll1d a(n);
  set<int> p;
  rep(i, n) cin >> a[i];
  rep(i, m) {
    int _;
    cin >> _;
    p.insert(_);
  }
  ll maxim = 0;
  for (int i = 0; i < n; i++) {
    if (maxim <= a[i]) {
      maxim = a[i];
    }
    else {
      if (!p.count(i)) {
        cout << "NO" << endl;
        return;
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