/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1385/submission/126230287
 * Submitted at: 2021-08-18 14:11:49
 * Problem URL: https://codeforces.com/contest/1385/problem/C
 * Result: WA
 * Execution Time: 171 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  ll n;
  cin >> n;
  deque<ll> dq;
  rep(i, n) {
    ll a;
    cin >> a;
    dq.push_back(a);
  }
  ll prev = 0;
  while (!dq.empty()) {
    ll fr = dq.front();
    ll ba = dq.back();
    if (fr >= prev && fr <= ba) {
      prev = fr;
      dq.pop_front();
    }
    else if (ba >= prev && ba <= fr) {
      prev = ba;
      dq.pop_back();
    }
    else if (fr >= prev) {
      prev = fr;
      dq.pop_front();
    }
    else if (ba >= prev) {
      prev = ba;
      dq.pop_back();
    }
    else {
      break;
    }
  }
  cout << dq.size() << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}