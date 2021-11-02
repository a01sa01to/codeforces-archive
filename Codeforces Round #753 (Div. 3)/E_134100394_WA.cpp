/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1607/submission/134100394
 * Submitted at: 2021-11-03 00:33:57
 * Problem URL: https://codeforces.com/contest/1607/problem/E
 * Result: WA
 * Execution Time: 46 ms
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
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int sx = 1, sy = 1, nx = 1, ny = 1, dx = 1, dy = 1;
  rep(i, s.size()) {
    switch (s[i]) {
      case 'L':
        nx--;
        if (nx == 0) {
          if (sx + dx - 1 < m) {
            nx = 1;
            sx++;
          }
          else {
            goto end;
          }
        }
        break;
      case 'R':
        nx++;
        dx = max(dx, nx);
        if (nx > m) {
          goto end;
        }
        break;
      case 'D':
        ny++;
        dy = max(dy, ny);
        if (ny > n) {
          goto end;
        }
        break;
      case 'U':
        ny--;
        if (ny == 0) {
          if (sy + dy - 1 < n) {
            ny = 1;
            sy++;
          }
          else {
            goto end;
          }
        }
        break;
    }
  }
end:
  printf("%d %d\n", sy, sx);
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}