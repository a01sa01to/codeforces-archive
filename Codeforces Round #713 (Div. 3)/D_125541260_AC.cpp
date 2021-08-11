/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1512/submission/125541260
 * Submitted at: 2021-08-11 14:21:00
 * Problem URL: https://codeforces.com/contest/1512/problem/D
 * Result: AC
 * Execution Time: 358 ms
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
  ll1d b(n + 2), sum(n + 3);
  rep(i, n + 2) { cin >> b[i]; }
  sort(all(b));
  sum[0] = 0;
  rep(i, n + 2) { sum[i + 1] = b[i] + sum[i]; }

  ll x = 0;
  ll su = b[n + 1];

  // 最後のelem が sum
  // b[i] が追加されたやつ → sum[n+1] - b[i] = b[n+1]
  const ll del = sum[n + 1] - b[n + 1];
  rep(i, n + 1) {
    if (b[i] == del) { x = b[i]; }
  }
  // 2番目のelemがsum → 最後のelemが追加されたやつ
  if (!x) {
    if (sum[n] == b[n]) {
      su = b[n];
      x = b[n + 1];
    }
    else {
      cout << -1 << endl;
      return;
    }
  }
  bool remX = false;
  bool remS = false;
  rep(i, n + 2) {
    if (!remX && b[i] == x) {
      remX = true;
    }
    else if (!remS && b[i] == su) {
      remS = true;
    }
    else {
      cout << b[i] << " ";
    }
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) { solve(); }
  return 0;
}