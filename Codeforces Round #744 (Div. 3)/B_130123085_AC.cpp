/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1579/submission/130123085
 * Submitted at: 2021-09-29 00:01:55
 * Problem URL: https://codeforces.com/contest/1579/problem/B
 * Result: AC
 * Execution Time: 124 ms
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
  vector<P> ans(0);
  while (!a.empty()) {
    auto itr = max_element(all(a));
    if (*itr == a.back()) a.pop_back();
    else {
      ans.push_back({ distance(a.begin(), itr) + 1, a.size() });
      a.erase(itr);
    }
  }
  cout << ans.size() << endl;
  for (P v : ans) printf("%lld %lld 1\n", v.first, v.second);
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}