/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1538/submission/125441522
 * Submitted at: 2021-08-10 13:41:58
 * Problem URL: https://codeforces.com/contest/1538/problem/B
 * Result: AC
 * Execution Time: 202 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    ll n;
    cin >> n;
    ll1d a(n);
    double sum = 0;
    rep(i, n) {
      cin >> a[i];
      sum += a[i];
    }
    double avg = sum / n;
    if (floor(avg) != avg) {
      cout << -1 << endl;
      continue;
    }
    sort(all(a), greater<ll>());
    ll ok = n, ng = -1;
    while (abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if (a[mid] <= avg) { ok = mid; }
      else {
        ng = mid;
      }
    }
    cout << ok << endl;
  }
  return 0;
}