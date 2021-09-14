/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1213/submission/128781767
 * Submitted at: 2021-09-14 13:10:09
 * Problem URL: https://codeforces.com/contest/1213/problem/A
 * Result: AC
 * Execution Time: 30 ms
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
  int odd = 0, even = 0;
  rep(i, n) {
    int x;
    cin >> x;
    if (x % 2 == 0) even++;
    else
      odd++;
  }
  cout << min(even, odd) << endl;
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while(t--) solve();
  solve();
  return 0;
}