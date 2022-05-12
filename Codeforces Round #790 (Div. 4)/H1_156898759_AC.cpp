/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1676/submission/156898759
 * Submitted at: 2022-05-12 17:32:04
 * Problem URL: https://codeforces.com/contest/1676/problem/H1
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

template<class T>
struct fenwick_tree {
  public:
  fenwick_tree(): _n(0) {}
  explicit fenwick_tree(int n): _n(n), data(n) {}

  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] += T(x);
      p += p & -p;
    }
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

  private:
  int _n;
  std::vector<T> data;

  T sum(int r) {
    T s = 0;
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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  fenwick_tree<ll> ft(n + 1);
  rep(i, n) {
    ans += ft.sum(a[i], n + 1);
    ft.add(a[i], 1);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}