/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1551/submission/123470098
 * Submitted at: 2021-07-23 23:58:05
 * Problem URL: https://codeforces.com/contest/1551/problem/A
 * Result: AC
 * Execution Time: 46 ms
 */

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define loop(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  loop(_, t) {
    ll n;
    cin >> n;
    ll ans = n / 3;
    if (ans * 3 + 1 == n) { cout << ans + 1 << " " << ans << endl; }
    else if (ans * 3 + 2 == n) {
      cout << ans << " " << ans + 1 << endl;
    }
    else {
      cout << ans << " " << ans << endl;
    }
  }
  return 0;
}