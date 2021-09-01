/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1256/submission/127570389
 * Submitted at: 2021-09-01 13:23:42
 * Problem URL: https://codeforces.com/contest/1256/problem/B
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
  int n;
  cin >> n;
  ll1d a(n);
  rep(i, n) cin >> a[i];
  vector<bool> used(n - 1, false);
  rep(i, n) rep(j, n - 1) {
    if (a[j + 1] == i + 1) {
      for (ll k = j; k >= i; k--) {
        if (used[k]) break;
        else {
          used[k] = true;
          swap(a[k], a[k + 1]);
        }
      }
    }
  }
  rep(i, n) cout << a[i] << " ";
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}