/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1579/submission/130143423
 * Submitted at: 2021-09-29 00:29:38
 * Problem URL: https://codeforces.com/contest/1579/problem/D
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
  priority_queue<P> pq;
  rep(i, n) {
    P a;
    cin >> a.first;
    a.second = i + 1;
    if (a.first != 0) {
      pq.push(a);
    }
  }
  vector<P> ans;
  while (pq.size() > 1) {
    P a = pq.top();
    pq.pop();
    P b = pq.top();
    pq.pop();
    ll delta = a.first - b.first;
    rep(_, b.first) {
      if (a.second > b.second) {
        ans.push_back({ b.second, a.second });
      }
      else {
        ans.push_back({ a.second, b.second });
      }
    }
    if (delta != 0) {
      pq.push({ delta, a.second });
    }
  }
  cout << ans.size() << endl;
  for (P x : ans) printf("%lld %lld\n", x.first, x.second);
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}