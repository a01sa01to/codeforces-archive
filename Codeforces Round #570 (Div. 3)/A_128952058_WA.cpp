/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1183/submission/128952058
 * Submitted at: 2021-09-16 13:11:37
 * Problem URL: https://codeforces.com/contest/1183/problem/A
 * Result: WA
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
  rep(i, 5) {
    int tmp = n + i;
    int sum = (tmp / 1000) + ((tmp / 100) % 10) + ((tmp / 10) % 10) + (tmp % 10);
    // cout << "[DEB] " << tmp << " " << sum << endl;
    if (sum % 4 == 0) {
      cout << tmp << endl;
      break;
    }
  }
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while(t--) solve();
  solve();
  return 0;
}