/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1234/submission/128108639
 * Submitted at: 2021-09-07 17:49:52
 * Problem URL: https://codeforces.com/contest/1234/problem/D
 * Result: AC
 * Execution Time: 763 ms
 */

#include <bits/stdc++.h>
using namespace std;
// #if __has_include(<atcoder/all>)
//   #include <atcoder/all>
// using namespace atcoder;
// #endif
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

namespace atcoder {
  template<class T>
  struct fenwick_tree {
    public:
    fenwick_tree(): _n(0) {}
    explicit fenwick_tree(int n): _n(n), data(n) {}

    void add(int p, T x) {
      assert(0 <= p && p < _n);
      p++;
      while (p <= _n) {
        data[p - 1] += x;
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

}  // namespace atcoder

void solve() {
  string s;
  cin >> s;
  vector<atcoder::fenwick_tree<int>> v(26, atcoder::fenwick_tree<int>(s.size()));
  rep(i, s.size()) {
    v[s[i] - 'a'].add(i, 1);
  }
  int q;
  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      v[s[pos] - 'a'].add(pos, -1);
      v[c - 'a'].add(pos, 1);
      swap(s[pos], c);
    }
    else {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      rep(i, 26) {
        ans += (v[i].sum(l - 1, r) > 0);
      }
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