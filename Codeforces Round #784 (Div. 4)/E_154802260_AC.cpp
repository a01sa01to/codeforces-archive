/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1669/submission/154802260
 * Submitted at: 2022-04-24 11:36:48
 * Problem URL: https://codeforces.com/contest/1669/problem/E
 * Result: AC
 * Execution Time: 312 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  map<string, ll> cnt;
  rep(i, n) cnt[s[i]]++;
  ll ans = 0;
  for (auto [key, val] : cnt) {
    // 前
    rep(i, 26) {
      string t = key;
      t[0] = 'a' + i;
      if (key == t) continue;
      ans += val * cnt[t];
    }
    // 後
    rep(i, 26) {
      string t = key;
      t[1] = 'a' + i;
      if (key == t) continue;
      ans += val * cnt[t];
    }
  }
  cout << ans / 2 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}