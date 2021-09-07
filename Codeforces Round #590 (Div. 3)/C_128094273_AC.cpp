/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1234/submission/128094273
 * Submitted at: 2021-09-07 13:47:58
 * Problem URL: https://codeforces.com/contest/1234/problem/C
 * Result: AC
 * Execution Time: 93 ms
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
  string s, t;
  cin >> s >> t;
  bool isTop = true, prevTop = false;
  int i = 0;
  while (i < n) {
    if (isTop) {
      if (s[i] >= '3') {
        if (t[i] <= '2') {
          break;
        }
        isTop = false;
      }
    }
    else {
      if (t[i] >= '3') {
        if (s[i] <= '2') {
          break;
        }
        isTop = true;
      }
    }
    i++;
  }
  if (i == n && isTop == false) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}