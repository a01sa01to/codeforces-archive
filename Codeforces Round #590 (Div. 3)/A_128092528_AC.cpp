/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1234/submission/128092528
 * Submitted at: 2021-09-07 13:03:19
 * Problem URL: https://codeforces.com/contest/1234/problem/A
 * Result: AC
 * Execution Time: 46 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
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
  long double sum = 0;
  rep(i, n) {
    int a;
    cin >> a;
    sum += a;
  }
  cout << int(ceil(sum / n)) << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}