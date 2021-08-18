/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1385/submission/126229275
 * Submitted at: 2021-08-18 13:54:50
 * Problem URL: https://codeforces.com/contest/1385/problem/A
 * Result: AC
 * Execution Time: 218 ms
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
  if (x == y && y == z) {
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
  }
  else if (x == y && x > z) {  // aがmax
    cout << "YES" << endl;
    cout << x << " " << z << " " << z << endl;
  }
  else if (y == z && z > x) {  // cがmax
    cout << "YES" << endl;
    cout << x << " " << x << " " << y << endl;
  }
  else if (z == x && x > y) {  // bがmax
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