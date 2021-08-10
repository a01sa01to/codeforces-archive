/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1538/submission/125443650
 * Submitted at: 2021-08-10 14:14:29
 * Problem URL: https://codeforces.com/contest/1538/problem/A
 * Result: AC
 * Execution Time: 31 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

ll sol(deque<ll> dq, ll maxim, ll minim, bool fromL, bool contL) {
  ll ans = 0;
  bool got = false;
  while (!dq.empty()) {
    ll now = (fromL ? dq.front() : dq.back());
    ans++;
    (fromL ? dq.pop_front() : dq.pop_back());
    if (now == maxim || now == minim) { break; }
  }
  while (!dq.empty()) {
    ll now = (contL ? dq.front() : dq.back());
    ans++;
    (contL ? dq.pop_front() : dq.pop_back());
    if (now == maxim || now == minim) { break; }
  }
  return ans;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    int n;
    cin >> n;
    deque<ll> dq;
    ll minim = 1e3, maxim = -1;
    rep(i, n) {
      ll a;
      cin >> a;
      dq.push_back(a);
      minim = min(minim, a);
      maxim = max(maxim, a);
    }

    ll ans = sol(dq, maxim, minim, false, false);
    ans = min(ans, sol(dq, maxim, minim, false, true));
    ans = min(ans, sol(dq, maxim, minim, true, false));
    ans = min(ans, sol(dq, maxim, minim, true, true));
    cout << ans << endl;
  }
  return 0;
}