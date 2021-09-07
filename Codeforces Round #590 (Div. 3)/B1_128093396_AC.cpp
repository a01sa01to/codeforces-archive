/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1234/submission/128093396
 * Submitted at: 2021-09-07 13:26:07
 * Problem URL: https://codeforces.com/contest/1234/problem/B1
 * Result: AC
 * Execution Time: 15 ms
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
  int n, k;
  cin >> n >> k;
  deque<int> dq;
  set<int> showing;
  rep(i, n) {
    int id;
    cin >> id;
    if (!showing.count(id)) {
      if (dq.size() >= k) {
        int rem = dq.front();
        dq.pop_front();
        showing.erase(rem);
      }
      showing.insert(id);
      dq.push_back(id);
    }
  }
  vector<int> ans;
  while (!dq.empty()) {
    int id = dq.back();
    dq.pop_back();
    ans.push_back(id);
  }
  cout << ans.size() << endl;
  for (int x : ans) { cout << x << " "; }
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