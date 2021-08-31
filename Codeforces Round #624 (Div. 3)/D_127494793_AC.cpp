/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1311/submission/127494793
 * Submitted at: 2021-08-31 14:32:50
 * Problem URL: https://codeforces.com/contest/1311/problem/D
 * Result: AC
 * Execution Time: 155 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  ll1d ans = { ll(1e10), 0, 0, 0 };
  for (int i = 1; i <= 2 * a; i++)
    for (int j = i; j <= 2 * b; j += i)
      for (int k = j; k <= 2 * c; k += j) {
        ll tmp = abs(a - i) + abs(b - j) + abs(c - k);
        if (ans[0] > tmp) {
          ans[0] = tmp;
          ans[1] = i;
          ans[2] = j;
          ans[3] = k;
        }
      }
  cout << ans[0] << endl
       << ans[1] << " " << ans[2] << " " << ans[3] << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}