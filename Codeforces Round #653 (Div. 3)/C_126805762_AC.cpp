/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1374/submission/126805762
 * Submitted at: 2021-08-24 14:16:06
 * Problem URL: https://codeforces.com/contest/1374/problem/C
 * Result: AC
 * Execution Time: 31 ms
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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll dep = 0;
  ll ans = 0;
  rep(i, n) {
    if (s[i] == '(') {
      dep++;
    }
    else {
      dep--;
    }
    if (dep < 0) {
      ans = min(ans, dep);
    }
  }
  cout << -ans << endl;
  return;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}