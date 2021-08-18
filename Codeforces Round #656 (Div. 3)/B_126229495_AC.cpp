/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1385/submission/126229495
 * Submitted at: 2021-08-18 13:58:41
 * Problem URL: https://codeforces.com/contest/1385/problem/B
 * Result: AC
 * Execution Time: 78 ms
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
  int n;
  cin >> n;
  vector<bool> seen(n, false);
  rep(i, 2 * n) {
    int p;
    cin >> p;
    if (!seen[p - 1]) {
      cout << p << " ";
      seen[p - 1] = true;
    }
  }
  cout << endl;
  return;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}