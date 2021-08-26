/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1353/submission/127026730
 * Submitted at: 2021-08-26 16:26:11
 * Problem URL: https://codeforces.com/contest/1353/problem/E
 * Result: AC
 * Execution Time: 233 ms
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
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll1d sum(n + 1, 0);
  rep(i, n) {
    sum[i + 1] = sum[i] + (s[i] - '0');
  }
  ll1d dp(n, 1e10);  // i番目がONのとき、それ以下のランプが最小でいくつ変える必要があるか
  dp[0] = 0;
  // cout << "[check point] 1" << endl;
  rep(i, n) {
    // i番目が最小の場合
    ll f = sum[i] - (s[i] - '1');
    ll g = 1e10;
    // i番目が最小でない場合
    if (i - k >= 0) {
      g = dp[i - k] + (sum[i] - sum[i - k + 1]) - (s[i] - '1');
    }
    dp[i] = min(f, g);
  }
  // cout << "[check point] 2" << endl;
  rep(i, n) {
    dp[i] = dp[i] + sum[n] - sum[i + 1];  // これ以降ない場合
  }
  // 全部OFFの場合
  dp.push_back(sum[n] - sum[0]);
  // cout << "[check point] 3" << endl;
  cout << *min_element(all(dp)) << endl;
  // cout << "[check point] 4" << endl;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}