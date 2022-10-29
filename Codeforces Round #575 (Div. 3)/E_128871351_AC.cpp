/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1196/submission/128871351
 * Submitted at: 2021-09-15 14:34:15
 * Problem URL: https://codeforces.com/contest/1196/problem/E
 * Result: AC
 * Execution Time: 592 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  ll b, w;
  cin >> b >> w;
  bool swapped = (b > w);
  if (swapped) swap(b, w);
  if (w > 3 * b + 1) {
    cout << "NO" << endl;
    return;
  }
  vector<P> ans;
  cout << "YES" << endl;
  int chkx = 3, chky = 2;
  // b<=w
  while (b > 0) {
    if (chkx % 2 == chky % 2) {
      // 白
      w--;
    }
    else {
      // 黒
      b--;
    }
    ans.push_back({ chkx++, chky });
  }
  chky = 1;
  int chkx1 = 3;
  while (w > 0 && chkx1 < chkx) {
    if (chkx1 % 2 == chky % 2) {
      // 白
      ans.push_back({ chkx1, chky });
      w--;
    }
    chkx1++;
  }
  chky = 3, chkx1 = 3;
  while (w > 0 && chkx1 < chkx) {
    if (chkx1 % 2 == chky % 2) {
      // 白
      ans.push_back({ chkx1, chky });
      w--;
    }
    chkx1++;
  }
  if (w >= 1) ans.push_back({ 2, 2 });
  if (w >= 2) ans.push_back({ chkx, 2 });
  for (P p : ans) {
    if (swapped) {
      cout << p.first + 1 << " " << p.second << endl;
    }
    else {
      cout << p.first << " " << p.second << endl;
    }
  }
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}