/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1213/submission/128791188
 * Submitted at: 2021-09-14 15:53:00
 * Problem URL: https://codeforces.com/contest/1213/problem/G
 * Result: AC
 * Execution Time: 1216 ms
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
typedef tuple<ll, ll, ll> TP;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

struct dsu {
  public:
  dsu(): _n(0) {}
  explicit dsu(ll n): _n(n), parent_or_size(n, -1) {}

  ll merge(ll a, ll b) {
    ll x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(ll a, ll b) {
    return leader(a) == leader(b);
  }

  ll leader(ll a) {
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  ll size(ll a) {
    return -parent_or_size[leader(a)];
  }

  ll2d groups() {
    ll1d leader_buf(_n), group_size(_n);
    for (ll i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    ll2d result(_n);
    for (ll i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (ll i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
      std::remove_if(result.begin(), result.end(),
                     [&](const std::vector<ll>& v) {
                       return v.empty();
                     }),
      result.end());
    return result;
  }

  private:
  ll _n;
  ll1d parent_or_size;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<TP> vec;
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    vec.push_back({ --u, --v, w });
  }
  vector<P> pea;
  rep(i, m) {
    int x;
    cin >> x;
    pea.push_back({ i, x });
  }
  sort(all(vec), [](TP& a, TP& b) {
    return get<2>(a) < get<2>(b);
  });
  sort(all(pea), [](P& a, P& b) {
    return a.second < b.second;
  });
  dsu d(n);
  ll tmp = 0;
  ll1d ans(m);
  ll pos = 0;
  rep(i, m) {
    while (pos < n - 1 && get<2>(vec[pos]) <= pea[i].second) {
      auto [u, v, w] = vec[pos];
      tmp += d.size(u) * d.size(v);
      d.merge(u, v);
      pos++;
    }
    ans[pea[i].first] = tmp;
  }
  sort(all(pea));
  rep(i, m) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  // int t;
  // cin >> t;
  // while (t--) solve();
  solve();
  return 0;
}