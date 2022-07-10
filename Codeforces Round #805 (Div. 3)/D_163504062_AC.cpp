/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1702/submission/163504062
 * Submitted at: 2022-07-11 00:01:31
 * Problem URL: https://codeforces.com/contest/1702/problem/D
 * Result: AC
 * Execution Time: 46 ms
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
  string s;
  int p;
  cin >> s >> p;
  vector<int> cnt(26, 0);
  rep(i, s.size()) cnt[s[i] - 'a']++;
  int nowScore = 0;
  rep(i, 26) nowScore += cnt[i] * (i + 1);
  Debug(cnt, nowScore);
  for (int i = 25; i >= 0; i--) {
    int delta = nowScore - p;
    if (cnt[i] * (i + 1) <= delta) {
      nowScore -= cnt[i] * (i + 1);
      cnt[i] = 0;
    }
    else {
      int minus = (delta + i) / (i + 1);
      nowScore -= minus * (i + 1);
      cnt[i] -= minus;
    }
    Debug(cnt, nowScore, i);
  }
  vector<int> used(26, 0);
  rep(i, s.size()) {
    int idx = s[i] - 'a';
    if (cnt[idx] > used[idx]) {
      cout << s[i];
      used[idx]++;
    }
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}