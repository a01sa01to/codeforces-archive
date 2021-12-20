/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1619/submission/140017485
 * Submitted at: 2021-12-20 23:36:48
 * Problem URL: https://codeforces.com/contest/1619/problem/A
 * Result: AC
 * Execution Time: 0 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if (n % 2 == 1) cout << "NO" << endl;
  else {
    string a = s.substr(0, n / 2), b = s.substr(n / 2);
    if (a == b) cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}