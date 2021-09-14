/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1213/submission/128787854
 * Submitted at: 2021-09-14 15:01:07
 * Problem URL: https://codeforces.com/contest/1213/problem/E
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
  string s, t;
  cin >> s >> t;
  string abc = "abc";
  vector<string> chk;
  do {
    string tmp1 = "";
    string tmp2 = "";
    rep(i, n) {
      tmp1 += abc;
    }
    rep(i, 3) rep(j, n) {
      tmp2 += abc[i];
    }
    chk.push_back(tmp1);
    chk.push_back(tmp2);
  } while (next_permutation(all(abc)));

  cout << "YES" << endl;
  for (string x : chk) {
    auto itrs = x.find(s);
    auto itrt = x.find(t);
    if (itrs == string::npos && itrt == string::npos) {
      cout << x << endl;
      break;
    }
  }
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while (t--) solve();
  solve();
  return 0;
}