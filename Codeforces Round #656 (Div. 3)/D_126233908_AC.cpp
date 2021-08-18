/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1385/submission/126233908
 * Submitted at: 2021-08-18 15:06:58
 * Problem URL: https://codeforces.com/contest/1385/problem/D
 * Result: AC
 * Execution Time: 93 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

ll n;
string s;

ll toChange(ll l, ll r, char c) {  // [l,r)
  if (r - l == 1) { return s[l] != c; }
  const ll mid = (r + l) / 2;
  const ll len = (r - l) / 2;
  ll changeL = len;
  ll changeR = len;
  rep(i, r - l) {
    if (s[l + i] == c) {
      if (i < len) { changeL--; }
      else {
        changeR--;
      }
    }
  }
  changeL += toChange(mid, r, c + 1);
  changeR += toChange(l, mid, c + 1);
  // cout << l << " " << r << " " << c << " | " << changeL << " " << changeR << endl;
  return min(changeL, changeR);
}

void solve() {
  cin >> n;
  cin >> s;
  cout << toChange(0, n, 'a') << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}