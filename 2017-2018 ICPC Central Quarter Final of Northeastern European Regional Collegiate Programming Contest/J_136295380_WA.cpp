/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/gym/102788/submission/136295380
 * Submitted at: 2021-11-21 09:21:42
 * Problem URL: https://codeforces.com/gym/102788/problem/J
 * Result: WA
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < n; i++)
int main() {
  ll n, m;
  scanf("%lld", &n);
  vector<ll> a(n), b(n);
  rep(i, n) scanf("%lld", &a[i]);
  rep(i, n) scanf("%lld", &b[i]);
  vector<ll> sum(n + 1, 0);
  rep(i, n) sum[i + 1] = sum[i] + (a[i] - b[i]) * (a[i] - b[i]);
  scanf("%lld", &m);
  rep(_, m) {
    ll i, j;
    scanf("%lld %lld", &i, &j);
    printf("%.5Lf\n", sqrt(ld(sum[j] - sum[i - 1])));
  }
}