/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1249/submission/127661538
 * Submitted at: 2021-09-02 13:36:20
 * Problem URL: https://codeforces.com/contest/1249/problem/C1
 * Result: AC
 * Execution Time: 30 ms
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

ll1d ans;

void solve() {
  int n;
  cin >> n;
  ll ok = ans.size() - 1, ng = -1;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    if (ans[mid] >= n) { ok = mid; }
    else {
      ng = mid;
    }
  }
  cout << ans[ok] << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  for (ll now = 1; now <= 20000; now *= 3) {
    ll s = ans.size();
    ans.push_back(now);
    rep(i, s) {
      ans.push_back(now + ans[i]);
    }
  }
  sort(all(ans));
  while (t--) solve();
  return 0;
}