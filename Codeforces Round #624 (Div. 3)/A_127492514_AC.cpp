/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1311/submission/127492514
 * Submitted at: 2021-08-31 13:43:03
 * Problem URL: https://codeforces.com/contest/1311/problem/A
 * Result: AC
 * Execution Time: 61 ms
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
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << endl;
  }
  else if (a % 2 == b % 2 && a > b) {
    cout << 1 << endl;
  }
  else if (a % 2 == b % 2) {
    cout << 2 << endl;
  }
  else if (a > b) {
    cout << 2 << endl;
  }
  else {
    cout << 1 << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}