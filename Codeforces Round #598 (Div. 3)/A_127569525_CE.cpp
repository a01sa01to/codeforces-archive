/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1256/submission/127569525
 * Submitted at: 2021-09-01 13:02:22
 * Problem URL: https://codeforces.com/contest/1256/problem/A
 * Result: CE
 * Execution Time: 0 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int a, b, n, s;
  cin >> a >> b >> n >> s;
  if (a * n > s) {
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