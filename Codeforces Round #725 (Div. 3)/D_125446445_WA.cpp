/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1538/submission/125446445
 * Submitted at: 2021-08-10 14:55:17
 * Problem URL: https://codeforces.com/contest/1538/problem/D
 * Result: WA
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

// 高々 10くらい
vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (ll a = 2; a * a <= n; a++) {
    if (n % a != 0) continue;
    ll ex = 0;  // 指数
    while (n % a == 0) {
      ex++;
      n /= a;
    }
    res.push_back({ a, ex });
  }
  if (n != 1) res.push_back({ n, 1 });
  sort(all(res));
  return res;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0;
    ll i = 0, j = 0;
    vector<pair<ll, ll>> div_a = prime_factorize(a);
    vector<pair<ll, ll>> div_b = prime_factorize(b);
    while (i < div_a.size() && j < div_b.size()) {
      if (div_a[i].first == div_b[j].first) {
        ans += div_a[i].second + div_b[j].second;
        i++;
        j++;
      }
      else if (div_a[i].first < div_b[j].first) {
        ans += div_a[i].second;
        i++;
      }
      else {
        ans += div_b[j].second;
        j++;
      }
    }
    if (a == 1) {
      rep(i, div_b.size()) {
        ans += div_b[i].second;
      }
    }
    if (b == 1) {
      rep(i, div_a.size()) {
        ans += div_a[i].second;
      }
    }
    if (a == b) {
      cout << ((k % 2 == 0 && ans >= k) ? "YES" : "NO") << endl;
    }
    else {
      cout << (ans >= k ? "YES" : "NO") << endl;
    }
  }
  return 0;
}