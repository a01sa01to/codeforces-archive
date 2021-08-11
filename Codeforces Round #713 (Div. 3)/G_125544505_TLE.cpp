/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1512/submission/125544505
 * Submitted at: 2021-08-11 15:06:50
 * Problem URL: https://codeforces.com/contest/1512/problem/G
 * Result: TLE
 * Execution Time: 2000 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

map<ll, ll> s;

ll sum_div(ll x) {
  ll sum = 0;
  for (ll i = 1; i * i <= x; i++) {
    if (x % i) continue;
    sum += i;
    if (i * i != x) {
      sum += x / i;
    }
  }
  return sum;
}

void solve() {
  ll c;
  cin >> c;
  if (s[c]) { cout << s[c] << endl; }
  else {
    cout << -1 << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(i, 1e6) {
    ll sum = sum_div(i + 1);
    if (!s[sum]) {
      s[sum] = i + 1;
    }
  }
  rep(_, t) { solve(); }
  return 0;
}