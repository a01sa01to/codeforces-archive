/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1538/submission/125440557
 * Submitted at: 2021-08-10 13:25:54
 * Problem URL: https://codeforces.com/contest/1538/problem/A
 * Result: WA
 * Execution Time: 15 ms
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
    int n;
    cin >> n;
    ll1d a(n);
    rep(i, n) { cin >> a[i]; }
    auto minim = distance(a.begin(), min_element(all(a)));
    auto maxim = distance(a.begin(), max_element(all(a)));

    int ans;
    // 左からminimをとる
    if (minim + 1 <= n - minim && minim < maxim) {
      ans = minim + 1;
      maxim -= minim + 1;
      n -= minim + 1;
      ans += min(maxim + 1, n - maxim);
    }
    // 右からminimをとる
    else if (minim + 1 > n - minim && minim > maxim) {
      ans = n - minim;
      n -= n - minim;
      ans += min(maxim + 1, n - maxim);
    }
    // 左からmaximをとる
    else if (maxim + 1 <= n - maxim && maxim < maxim) {
      ans = maxim + 1;
      minim -= maxim + 1;
      n -= maxim + 1;
      ans += min(minim + 1, n - minim);
    }
    else {
      ans = n - maxim;
      n -= n - maxim;
      ans += min(minim + 1, n - minim);
    }
    cout << ans << endl;
  }
  return 0;
}