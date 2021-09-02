/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1249/submission/127660595
 * Submitted at: 2021-09-02 13:15:15
 * Problem URL: https://codeforces.com/contest/1249/problem/B1
 * Result: AC
 * Execution Time: 61 ms
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
  ll1d p(n), book(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
    book[i] = i;
  }
  ll1d ans(n, 0);
  rep(d, n) {
    ll1d prev(n);
    copy(all(book), prev.begin());
    rep(i, n) {
      book[p[i]] = prev[i];
    }
    rep(i, n) {
      if (book[i] == i && ans[i] == 0) {
        ans[i] = d + 1;
        continue;
      }
    }
  }
  rep(i, n) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}