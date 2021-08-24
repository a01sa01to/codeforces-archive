/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1374/submission/126805334
 * Submitted at: 2021-08-24 14:09:07
 * Problem URL: https://codeforces.com/contest/1374/problem/B
 * Result: TLE
 * Execution Time: 1000 ms
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

vector<P> prime_factorize(ll n) {
  vector<P> ans;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    ll ex = 0;
    while (n % i == 0) {
      ex++;
      n /= i;
    }
    ans.push_back({ i, ex });
  }
  if (n != 1) ans.push_back({ n, 1 });
  return ans;
}

void solve() {
  ll n;
  cin >> n;
  vector<P> prime = prime_factorize(n);
  ll ex2 = 0, ex3 = 0;
  for (ll i = 2; i <= 3; i++) {
    if (n % i != 0) continue;
    ll ex = 0;
    while (n % i == 0) {
      ex++;
      n /= i;
    }
    if (i == 2) { ex2 = ex; }
    else {
      ex3 = ex;
    }
  }
  if (n != 1) {
    cout << -1 << endl;
  }
  else if (ex3 < ex2) {
    cout << -1 << endl;
  }
  else {
    cout << (ex3 - ex2) + ex3 << endl;
  }
  return;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}