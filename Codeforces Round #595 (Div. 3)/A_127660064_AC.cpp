/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1249/submission/127660064
 * Submitted at: 2021-09-02 13:04:00
 * Problem URL: https://codeforces.com/contest/1249/problem/A
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
  ll1d a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  bool isTwo = false;
  rep(i, n - 1) {
    if (a[i] + 1 == a[i + 1]) {
      isTwo = true;
    }
  }
  cout << (isTwo ? 2 : 1) << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}