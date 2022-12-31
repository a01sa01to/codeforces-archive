/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1770/submission/187423267
 * Submitted at: 2022-12-31 17:21:21
 * Problem URL: https://codeforces.com/contest/1770/problem/D
 * Result: WA
 * Execution Time: 202 ms
 */

#include <bits/stdc++.h>
using namespace std;
// #if __has_include(<atcoder/all>)
//   #include <atcoder/all>
// using namespace atcoder;
// #endif
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
 struct dsu {
  public:
  dsu(): _n(0) {}
  explicit dsu(int n): _n(n), parent_or_size(n, -1) {}
   int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }
   bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
   int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }
   int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }
   std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
      std::remove_if(result.begin(), result.end(),
                     [&](const std::vector<int>& v) {
                       return v.empty();
                     }),
      result.end());
    return result;
  }
   private:
  int _n;
  std::vector<int> parent_or_size;
};
 void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  dsu d(n);
  vector<int> self(n), edges(n, 0);
  rep(i, n) {
    int olda = d.leader(a[i] - 1), oldb = d.leader(b[i] - 1);
    d.merge(a[i] - 1, b[i] - 1);
    edges[d.leader(a[i] - 1)] = edges[olda] + edges[oldb] + 1;
    if (a[i] == b[i]) self[d.leader(a[i] - 1)]++;
  }
  ll ans = 1;
  auto g = d.groups();
  Debug(self, edges);
  Debug(g);
  for (auto vs : g) {
    int m = vs.size();
    int e = edges[d.leader(vs[0])];
    if (m > e) ans = 0;
    else if (self[d.leader(vs[0])] > 0) {
      ans *= n;
    }
    else {
      ans *= 2;
    }
    ans %= 998244353;
  }
  cout << ans << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}