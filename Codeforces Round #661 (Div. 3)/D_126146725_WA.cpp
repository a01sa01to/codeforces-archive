/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1399/submission/126146725
 * Submitted at: 2021-08-17 15:10:48
 * Problem URL: https://codeforces.com/contest/1399/problem/D
 * Result: WA
 * Execution Time: 0 ms
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
#define debug(var) \
  do { cout << #var << ": " << var << endl; } while (false)

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll c = 1;
  cout << 1 << " ";
  rep(i, n - 1) {
    if (s[i + 1] != s[i]) {
      c = 1;
    }
    else {
      c++;
    }
    cout << c << " ";
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    solve();
  }
  return 0;
}