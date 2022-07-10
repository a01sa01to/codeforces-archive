/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1702/submission/163565507
 * Submitted at: 2022-07-11 01:26:18
 * Problem URL: https://codeforces.com/contest/1702/problem/E
 * Result: WA
 * Execution Time: 108 ms
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
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n, 0);
  vector<pair<int, int>> v(n);
  rep(i, n) {
    cin >> v[i].first >> v[i].second;
    v[i].first--, v[i].second--;
    auto [a, b] = v[i];
    cnt[a]++, cnt[b]++;
  }
  Debug(cnt);
  bool chk = true;
  rep(i, n) {
    if (cnt[i] != 2) {
      chk = false;
      break;
    }
  }
  if (!chk) {
    cout << "NO" << endl;
    return;
  }
  set<int> s, t;
  rep(i, n) {
    auto [a, b] = v[i];
    if (a == b) {
      cout << "NO" << endl;
      return;
    }
    else if (!s.count(a) && !s.count(b)) {
      s.insert(a), s.insert(b);
    }
    else if (!t.count(a) && !t.count(b)) {
      t.insert(a), t.insert(b);
    }
    else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}