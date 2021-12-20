/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1619/submission/140079695
 * Submitted at: 2021-12-21 01:17:58
 * Problem URL: https://codeforces.com/contest/1619/problem/E
 * Result: WA
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> cnt(n + 1, 0);
  rep(i, n)++ cnt[a[i]];
  multiset<int, greater<int>> rem, zero;
  int sum = 0;
  bool flag = false, cant = false;  // ここまでに0となるものが出てきたかどうか
  rep(i, n + 1) {
    if (cant) {
      cout << -1 << " ";
    }
    else {
      if (!flag) {
        cout << cnt[i] << " ";
        if (cnt[i] == 0) flag = true;
      }
      else {
        int d = 0;
        auto itrzero = zero.begin(), itrrem = rem.begin();
        while (itrzero != zero.end()) {
          if (itrrem == rem.end()) {
            cout << -1 << " ";
            cant = true;
            break;
          }
          int delta = *itrzero++ - *itrrem++;
          if (delta < 0) {
            cout << -1 << " ";
            cant = true;
            break;
          }
          d += delta;
        }
        if (cant) continue;
        cout << d + cnt[i] << " ";
      }
    }
    if (cnt[i] > 1) {
      rep(_, cnt[i] - 1) {
        rem.insert(i);
      }
    }
    else if (cnt[i] == 0) {
      zero.insert(i);
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