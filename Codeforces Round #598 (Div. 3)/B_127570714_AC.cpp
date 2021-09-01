/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1256/submission/127570714
 * Submitted at: 2021-09-01 13:31:10
 * Problem URL: https://codeforces.com/contest/1256/problem/B
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
  int n;
  cin >> n;
  ll1d a(n);
  rep(i, n) cin >> a[i];
  int i = 0;
  while (i < n) {
    auto itr = distance(a.begin(), min_element(a.begin() + i, a.end()));
    // cout << "[DEB] " << itr << endl;
    for (int j = itr - 1; j >= i; j--) {
      swap(a[j], a[j + 1]);
    }
    if (i == itr) i++;
    else
      i = itr;
  }
  rep(i, n) cout << a[i] << " ";
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}