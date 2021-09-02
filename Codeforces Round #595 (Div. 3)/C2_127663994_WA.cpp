/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1249/submission/127663994
 * Submitted at: 2021-09-02 14:26:05
 * Problem URL: https://codeforces.com/contest/1249/problem/C2
 * Result: WA
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

vector<int> to_3shin(ll n) {
  vector<int> ans;
  while (n > 0) {
    ans.push_back(n % 3);
    n /= 3;
  }
  return ans;
}

ull from_3shin(vector<int> v) {
  ull ans = 0, pow3 = 1;
  rep(i, v.size()) {
    ans += pow3 * v[i];
    pow3 *= 3;
  }
  return ans;
}

void solve() {
  ull n;
  cin >> n;
  vector<int> sanshin = to_3shin(n);
  bool needChange = false;
  rep(i, sanshin.size()) {
    if (sanshin[i] == 0 && needChange) {
      needChange = false;
      sanshin[i] = 1;
    }
    else if (sanshin[i] == 2) {
      needChange = true;
      sanshin[i] = 0;
    }
    else if (needChange && sanshin[i] == 1) {
      sanshin[i] = 0;
    }
  }
  if (needChange) {
    rep(i, sanshin.size()) sanshin[i] = 0;
    sanshin.push_back(1);
  }
  cout << from_3shin(sanshin) << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}