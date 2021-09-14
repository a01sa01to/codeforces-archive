/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1213/submission/128787006
 * Submitted at: 2021-09-14 14:47:28
 * Problem URL: https://codeforces.com/contest/1213/problem/E
 * Result: AC
 * Execution Time: 31 ms
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
  // aa0 ab1 ac2 ba3 bb4 bc5 ca6 cb7 cc8
  int si = (s[0] - 'a') * 3 + (s[1] - 'a');
  int ti = (t[0] - 'a') * 3 + (t[1] - 'a');
  if (si > ti) swap(si, ti);
  // cout << si << ti << endl;
  cout << "YES" << endl;

  // aa aa = cbacba...
  // aa ab = cbacba...
  // aa bb = cbacba...
  // aa bc = cbacba...
  // aa ca = cbacba...
  // aa cc = cbacba...
  // aa ac = bcabca...
  // aa ba = bcabca...
  // aa cb = bcabca...
  if (si == 0) {
    if (ti != 2 && ti != 3 && ti != 7) {
      rep(i, n) cout << "cba";
    }
    else {
      rep(i, n) cout << "bca";
    }
  }
  // ab ab = cbacba...
  // ab bc = cbacba...
  // ab cc = cbacba...
  // ab bb = bacbac...
  // ab ca = bacbac...
  // ab ac = c...b...a...
  // ab cb = b...c...a...
  // ab ba = a...c...b...
  else if (si == 1) {
    if (ti == 1 || ti == 5 || ti == 8) {
      rep(i, n) cout << "cba";
    }
    else if (ti == 4 || ti == 6) {
      rep(i, n) cout << "bac";
    }
    else if (ti == 2) {
      rep(i, n) cout << "c";
      rep(i, n) cout << "b";
      rep(i, n) cout << "a";
    }
    else if (ti == 3) {
      rep(i, n) cout << "a";
      rep(i, n) cout << "c";
      rep(i, n) cout << "b";
    }
    else if (ti == 7) {
      rep(i, n) cout << "b";
      rep(i, n) cout << "c";
      rep(i, n) cout << "a";
    }
  }
  // ac ac = bcabca...
  // ac ba = bcabca...
  // ac bb = bcabca...
  // ac cb = bcabca...
  // ac cc = bcabca...
  // ac bc = c...b...a...
  // ac ca = c...b...a...
  else if (si == 2) {
    if (ti == 6 || ti == 5) {
      rep(i, n) cout << "c";
      rep(i, n) cout << "b";
      rep(i, n) cout << "a";
    }
    else {
      rep(i, n) cout << "bca";
    }
  }
  // ba ba = bcabca...
  // ba bb = bcabca...
  // ba cb = bcabca...
  // ba cc = bcabca...
  // ba bc = a...c...b...
  // ba ca = a...c...b...
  else if (si == 3) {
    if (ti == 6 || ti == 5) {
      rep(i, n) cout << "a";
      rep(i, n) cout << "c";
      rep(i, n) cout << "b";
    }
    else {
      rep(i, n) cout << "bca";
    }
  }
  // bb bb = cbacba...
  // bb bc = cbacba...
  // bb ca = cbacba...
  // bb cc = cbacba...
  // bb cb = bcabca...
  else if (si == 4) {
    if (ti == 7) {
      rep(i, n) cout << "bca";
    }
    else {
      rep(i, n) cout << "cba";
    }
  }
  // bc bc = cbacba...
  // bc ca = cbacba...
  // bc cb = c...a...b...
  // bc cc = cbacba...
  else if (si == 5) {
    if (ti == 7) {
      rep(i, n) cout << "c";
      rep(i, n) cout << "a";
      rep(i, n) cout << "b";
    }
    else {
      rep(i, n) cout << "cba";
    }
  }
  // ca ca = cbacba...
  // ca cb = a...b...c...
  // ca cc = cbacba...
  else if (si == 6) {
    if (ti == 7) {
      rep(i, n) cout << "a";
      rep(i, n) cout << "b";
      rep(i, n) cout << "c";
    }
    else {
      rep(i, n) cout << "cba";
    }
  }
  // cb cb = bcabca...
  // cb cc = bcabca...
  else if (si == 7) {
    rep(i, n) cout << "bca";
  }
  // cc cc = cbacba...
  else {
    rep(i, n) cout << "cba";
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while (t--) solve();
  solve();
  return 0;
}