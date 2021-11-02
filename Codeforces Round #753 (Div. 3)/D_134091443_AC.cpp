/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1607/submission/134091443
 * Submitted at: 2021-11-03 00:18:23
 * Problem URL: https://codeforces.com/contest/1607/problem/D
 * Result: AC
 * Execution Time: 436 ms
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
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int n;
  cin >> n;
  ll1d a(n);
  rep(i, n) cin >> a[i];
  string s;
  cin >> s;
  priority_queue<P, vector<P>, greater<P>> pq;
  rep(i, n) pq.push({ s[i] == 'R', a[i] });  // 青のうち、少ない順に入ってく
  ll i = 1;
  bool ans = true;
  while (!pq.empty()) {
    P t = pq.top();
    pq.pop();
    if (!t.first) {
      if (i > t.second) ans = false;
    }
    else {
      if (i < t.second) ans = false;
    }
    i++;
  }
  puts(ans ? "YES" : "NO");
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}