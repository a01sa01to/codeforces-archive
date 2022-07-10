/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1702/submission/163489214
 * Submitted at: 2022-07-10 23:49:14
 * Problem URL: https://codeforces.com/contest/1702/problem/C
 * Result: AC
 * Execution Time: 2059 ms
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
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> m;
  vector<int> u(n);
  rep(i, n) {
    cin >> u[i];
    m[u[i]].push_back(i);
  }
  while (k--) {
    int a, b;
    cin >> a >> b;
    if (!m.count(a)) {
      cout << "NO" << endl;
      continue;
    }
    int idx1 = *m[a].begin();
    if (!m.count(b)) {
      cout << "NO" << endl;
      continue;
    }
    auto itr2 = upper_bound(m[b].begin(), m[b].end(), idx1);
    if (itr2 == m[b].end()) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}