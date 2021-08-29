/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1556/submission/127391810
 * Submitted at: 2021-08-30 02:04:45
 * Problem URL: https://codeforces.com/contest/1556/problem/B
 * Result: WA
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
  vector<bool> a(n);
  int ans = 0, odd = 0, even = 0;
  rep(i, n) {
    int h;
    cin >> h;
    a[i] = (h % 2 == 1);
    if (a[i]) odd++;
    else
      even++;
  }
  if (abs(odd - even) > 1) {
    cout << -1 << endl;
    return;
  }
  int i = 0, j = 1;
  while (j < n) {
    bool changed = false;
    if (a[i] != a[j]) {
      ans += j - i - 1;
      if (changed) {
        a[i] = !a[i];
        a[j] = !a[j];
        changed = false;
      }
      i++;
      j = i + 1;
    }
    else {
      changed = true;
      j++;
    }
  }
  cout << ans << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}