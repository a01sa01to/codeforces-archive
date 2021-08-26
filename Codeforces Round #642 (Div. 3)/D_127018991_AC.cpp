/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1353/submission/127018991
 * Submitted at: 2021-08-26 14:29:37
 * Problem URL: https://codeforces.com/contest/1353/problem/D
 * Result: AC
 * Execution Time: 93 ms
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
  ll n;
  cin >> n;
  ll1d a(n, 0);
  auto comp = [](P& a, P& b) {
    ll lenA = (a.second - a.first);
    ll lenB = (b.second - b.first);
    if (lenA != lenB) {
      return lenA < lenB;
    }
    else {
      return a.first > b.first;
    }
  };
  priority_queue<P, vector<P>, decltype(comp)> pq { comp };
  pq.push({ 0, n - 1 });
  ll i = 1;
  while (!pq.empty()) {
    auto [l, r] = pq.top();
    pq.pop();
    ll mid = (l + r) / 2;
    a[mid] = i;
    i++;
    if (l != mid) pq.push({ l, mid - 1 });
    if (r != mid) pq.push({ mid + 1, r });
  }

  for (ll x : a) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}