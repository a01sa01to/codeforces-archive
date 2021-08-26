/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1353/submission/127016953
 * Submitted at: 2021-08-26 13:48:39
 * Problem URL: https://codeforces.com/contest/1353/problem/A
 * Result: AC
 * Execution Time: 62 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  ll n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << 0 << endl;
  }
  else if (n == 2) {
    cout << m << endl;
  }
  else {
    // 0とm/(n/2) = 2m/nを n/2回交互に
    cout << 2 * m << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}