/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1256/submission/127573150
 * Submitted at: 2021-09-01 14:28:43
 * Problem URL: https://codeforces.com/contest/1256/problem/D
 * Result: AC
 * Execution Time: 156 ms
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
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll cnt = 0, f = 0;
  rep(i, n) {
    if (s[i] == '0') {
      // cout << "[DEB] " << i << " " << f << " " << (cnt + i - f) << endl;
      if (cnt + i - f <= k) {
        swap(s[f], s[i]);
        cnt += i - f;
        f++;
      }
      else {
        swap(s[i], s[i - (k - cnt)]);
        break;
      }
    }
  }
  cout << s << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}