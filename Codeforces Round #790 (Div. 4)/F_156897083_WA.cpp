/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156897083
 * Submitted at: 2022-05-12 17:07:41
 * Problem URL: https://codeforces.com/contest/1676/problem/F
 * Result: WA
 * Execution Time: 30 ms
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

bool check(pair<int, int> tmp, pair<int, int> ans) {
  return ans.second - ans.first < tmp.second - tmp.first;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  map<int, int> mp;
  rep(i, n) mp[a[i]]++;

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  vector<pair<int, int>> v(0);
  {
    bool flag = false;
    pair<int, int> tmp = { 0, 0 };
    rep(i, a.size()) {
      if (!flag) {
        tmp.first = a[i];
        flag = true;
      }
      if (i + 1 == a.size() || a[i] != a[i + 1] - 1) {
        tmp.second = a[i];
        v.push_back(tmp);
        flag = false;
      }
    }
  }
  Debug(v);

  pair<int, int> ans = { 0, 0 };
  rep(i, v.size()) {
    auto [l, r] = v[i];
    pair<int, int> tmp = { l, l };
    for (int j = l; j <= r; ++j) {
      if (mp[j] < k) {
        tmp.second = j - 1;
        if (check(tmp, ans)) ans = tmp;
        tmp = { j + 1, j + 1 };
        Debug(j, ans);
      }
    }
    tmp.second = r;
    Debug(tmp, ans);
    if (check(tmp, ans)) ans = tmp;
  }

  auto [l, r] = ans;
  if (l + r == 0)
    cout << -1 << endl;
  else
    printf("%d %d\n", l, r);
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}