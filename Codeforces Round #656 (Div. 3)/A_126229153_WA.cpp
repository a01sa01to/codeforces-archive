/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1385/submission/126229153
 * Submitted at: 2021-08-18 13:52:31
 * Problem URL: https://codeforces.com/contest/1385/problem/A
 * Result: WA
 * Execution Time: 15 ms
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
  ll x, y, z;
  cin >> x >> y >> z;
  if (x == y == z) {
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
  }
  else if (x == y) {  // aがmax
    cout << "YES" << endl;
    cout << x << " " << z << " " << z << endl;
  }
  else if (y == z) {  // cがmax
    cout << "YES" << endl;
    cout << x << " " << x << " " << y << endl;
  }
  else if (z == x) {  // bがmax
    cout << "YES" << endl;
    cout << y << " " << x << " " << y << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}