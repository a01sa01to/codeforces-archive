/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1234/submission/128096826
 * Submitted at: 2021-09-07 14:40:44
 * Problem URL: https://codeforces.com/contest/1234/problem/D
 * Result: AC
 * Execution Time: 1028 ms
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
  string s;
  cin >> s;
  vector<set<int>> v(26);
  // cout << "[CP1]" << endl;
  rep(i, 26) v[i].insert(-1);
  rep(i, s.size()) {
    v[s[i] - 'a'].insert(i);
  }
  int q;
  cin >> q;
  // cout << "[CP2]" << endl;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      // cout << "[CP3]" << endl;
      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      v[s[pos] - 'a'].erase(pos);
      v[c - 'a'].insert(pos);
      swap(s[pos], c);
      // cout << "[CP4]" << endl;
    }
    else {
      int l, r;
      cin >> l >> r;
      // cout << "[CP5]" << endl;
      l--, r--;
      int ans = 0;
      rep(i, 26) {
        // cout << "[CP6] " << (i + 'a') << endl;
        auto L = v[i].lower_bound(l);
        if (L != v[i].end() && *L <= r) ans++;
      }
      // cout << "[CP7]" << endl;
      cout << ans << endl;
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