/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1183/submission/128955225
 * Submitted at: 2021-09-16 14:24:48
 * Problem URL: https://codeforces.com/contest/1183/problem/E
 * Result: AC
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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  set<string> st;
  queue<string> que;
  ll ans = 0;
  st.insert(s);
  que.push(s);
  while (!que.empty() && st.size() < k) {
    string str = que.front();
    que.pop();
    rep(i, str.size()) {
      string tmp = str;
      tmp.erase(i, 1);
      // cout << "[DEB] " << tmp << endl;
      if (!st.count(tmp) && st.size() < k) {
        ans += n - tmp.size();
        st.insert(tmp);
        que.push(tmp);
      }
    }
  }
  if (st.size() < k) cout << -1 << endl;
  else
    cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while (t--) solve();
  solve();
  return 0;
}
