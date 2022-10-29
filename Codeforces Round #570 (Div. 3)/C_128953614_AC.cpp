/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1183/submission/128953614
 * Submitted at: 2021-09-16 13:50:15
 * Problem URL: https://codeforces.com/contest/1183/problem/C
 * Result: AC
 * Execution Time: 982 ms
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
  ll k, n, a, b;
  cin >> k >> n >> a >> b;
  if (k > n * a) {
    cout << n << endl;
    return;
  }
  k -= n * a;
  ll ok = n + 1, ng = 0;
  ll dif = a - b;
  while ((ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if ((k + dif * mid) > 0) {
      ok = mid;
    }
    else {
      ng = mid;
    }
  }
  cout << n - ok << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}