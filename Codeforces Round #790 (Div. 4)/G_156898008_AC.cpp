/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156898008
 * Submitted at: 2022-05-12 17:21:03
 * Problem URL: https://codeforces.com/contest/1676/problem/G
 * Result: AC
 * Execution Time: 218 ms
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
  vector Graph(n, vector<int>(0));
  rep(i, n - 1) {
    int a;
    cin >> a;
    --a;
    Graph[a].push_back(i + 1);
  }
  string s;
  cin >> s;

  vector<pair<int, int>> memo(n, { -1, -1 });

  function<pair<int, int>(int)> dfs = [&](int i) {
    if (memo[i].first != -1) return memo[i];
    memo[i] = { s[i] == 'W', s[i] == 'B' };
    for (int j : Graph[i]) {
      auto [w, b] = dfs(j);
      memo[i].first += w;
      memo[i].second += b;
    }
    return memo[i];
  };
  dfs(0);
  Debug(Graph);
  Debug(memo);

  int ans = 0;
  rep(i, n) {
    if (memo[i].first == memo[i].second) ++ans;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}