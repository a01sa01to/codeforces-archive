/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1374/submission/126811186
 * Submitted at: 2021-08-24 15:34:24
 * Problem URL: https://codeforces.com/contest/1374/problem/E1
 * Result: WA
 * Execution Time: 358 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef tuple<ll, bool, bool> TP;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  cout << fixed << setprecision(15);
  ll n, k;
  cin >> n >> k;
  ll alice = 0, bob = 0;
  auto comp = [&](TP& a, TP& b) {
    auto [time1, al1, bo1] = a;
    auto [time2, al2, bo2] = b;
    ll scorea = time1 - (al1 + bo1) * 1000;
    ll scoreb = time2 - (al2 + bo2) * 1000;
    return scorea > scoreb;
  };
  priority_queue<TP, vector<TP>, decltype(comp)> read { comp };
  rep(i, n) {
    ll time, a, b;
    cin >> time >> a >> b;
    if (a) alice++;
    if (b) bob++;
    if (a || b) {
      read.push({ time, a, b });
    }
  }
  if (alice < k || bob < k) {
    cout << -1 << endl;
    return 0;
  }
  alice = k;
  bob = k;
  ll ans = 0;
  while ((alice || bob) && !read.empty()) {
    auto [time, a, b] = read.top();
    read.pop();
    ans += time;
    if (a) alice--;
    if (b) bob--;
  }
  cout << ans << endl;
  return 0;
}