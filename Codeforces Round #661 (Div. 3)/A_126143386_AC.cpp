/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1399/submission/126143386
 * Submitted at: 2021-08-17 14:16:55
 * Problem URL: https://codeforces.com/contest/1399/problem/A
 * Result: AC
 * Execution Time: 15 ms
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
  int n;
  cin >> n;
  ll1d a(n);
  rep(i, n) { cin >> a[i]; }
  sort(all(a));
  int i = 0;
  while (i + 1 < a.size()) {
    if (a[i + 1] - a[i] <= 1) {
      a.erase(a.begin() + i);
    }
    else {
      i++;
    }
  }
  if (a.size() == 1) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
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