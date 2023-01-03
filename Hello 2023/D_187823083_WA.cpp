/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1779/submission/187823083
 * Submitted at: 2023-01-04 01:41:24
 * Problem URL: https://codeforces.com/contest/1779/problem/D
 * Result: WA
 * Execution Time: 171 ms
 */

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
 template<class T, class U>
struct fenwick_tree {
  public:
  fenwick_tree(): _n(0) {}
  explicit fenwick_tree(int n): _n(n), data(n) {}
  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] += U(x);
      p += p & -p;
    }
  }
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }
   private:
  int _n;
  std::vector<U> data;
  U sum(int r) {
    U s = 0;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;
    }
    return s;
  }
};
 void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  int m;
  cin >> m;
  vector<int> x(m);
  rep(i, m) cin >> x[i];
  sort(x.begin(), x.end());
  rep(i, n) {
    if (a[i] < b[i]) {
      Debug(a[i], b[i]);
      cout << "No" << endl;
      return;
    }
  }
  rep(i, n) {
    if (a[i] == b[i]) continue;
    auto it1 = lower_bound(x.begin(), x.end(), b[i]);
    auto it2 = upper_bound(x.begin(), x.end(), b[i]);
    if (distance(it1, it2) == 0) {
      Debug(b[i]);
      cout << "No" << endl;
      return;
    }
  }
  map<int, int> mp, mpinv;
  int cnt = 0;
  {
    set<int> st;
    rep(i, n) {
      st.insert(b[i]);
    }
    for (auto e : st) {
      mp[e] = cnt;
      mpinv[cnt] = e;
      cnt++;
    }
  }
  fenwick_tree<ll, ll> ft(cnt);
  vector<int> needs(cnt, 0);
  vector<int> prev(cnt, -1);
  rep(i, n) {
    int p = mp[b[i]];
    needs[p] += (prev[p] != ft.sum(p, cnt));
    ft.add(p, 1);
    prev[p] = ft.sum(p, cnt);
  }
  rep(i, cnt) {
    int p = mpinv[i];
    auto it1 = lower_bound(x.begin(), x.end(), p);
    auto it2 = upper_bound(x.begin(), x.end(), p);
    if (distance(it1, it2) != 0 && distance(it1, it2) < needs[i]) {
      Debug(p, needs[i], distance(it1, it2));
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
 int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}