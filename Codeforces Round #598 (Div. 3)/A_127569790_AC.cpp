/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1256/submission/127569790
 * Submitted at: 2021-09-01 13:09:51
 * Problem URL: https://codeforces.com/contest/1256/problem/A
 * Result: AC
 * Execution Time: 109 ms
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
  ll a, b, n, s;
  cin >> a >> b >> n >> s;
  if (a * n >= s) {
    s %= n;
  }
  else {
    s -= a * n;
  }
  if (b >= s) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}