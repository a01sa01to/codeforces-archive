/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1249/submission/127661248
 * Submitted at: 2021-09-02 13:30:20
 * Problem URL: https://codeforces.com/contest/1249/problem/B2
 * Result: AC
 * Execution Time: 280 ms
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
  ll1d p(n);
  ll1d ans(n, 0);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }
  vector<bool> visited(n, false);
  rep(i, n) {
    if (!visited[i]) {
      ll1d cycle;
      ll position = p[i];
      while (!visited[i]) {
        cycle.push_back(position);
        visited[position] = true;
        position = p[position];
      }
      rep(j, cycle.size()) ans[cycle[j]] = cycle.size();
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