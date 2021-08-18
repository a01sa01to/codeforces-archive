/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1385/submission/126231155
 * Submitted at: 2021-08-18 14:25:19
 * Problem URL: https://codeforces.com/contest/1385/problem/C
 * Result: AC
 * Execution Time: 343 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

bool chk(deque<ll> dq, ll start) {
  ll prev = 0;
  if (start >= dq.size()) { return false; }
  while (start--) { dq.pop_front(); }
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
  return dq.empty();
}

void solve() {
  ll n;
  cin >> n;
  deque<ll> dq;
  rep(i, n) {
    ll a;
    cin >> a;
    dq.push_back(a);
  }
  ll ok = n - 1, ng = -1;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (chk(dq, mid)) { ok = mid; }
    else {
      ng = mid;
    }
  }
  cout << ok << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}