/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1234/submission/128093216
 * Submitted at: 2021-09-07 13:21:29
 * Problem URL: https://codeforces.com/contest/1234/problem/B1
 * Result: WA
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
  int n, k;
  cin >> n >> k;
  deque<int> dq;
  int maximId = 0;
  set<int> showing;
  rep(i, n) {
    int id;
    cin >> id;
    if (dq.size() >= k && !showing.count(id)) {
      int pp = dq.front();
      dq.pop_front();
      showing.erase(pp);
      dq.push_back(id);
      showing.insert(id);
    }
    else if (dq.size() < k) {
      dq.push_back(id);
      showing.insert(id);
    }
    maximId = max(maximId, id);
  }
  vector<bool> s(maximId, false);
  vector<int> ans;
  while (!dq.empty()) {
    int id = dq.back();
    dq.pop_back();
    if (!s[id - 1] && ans.size() < k) {
      s[id - 1] = true;
      ans.push_back(id);
    }
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