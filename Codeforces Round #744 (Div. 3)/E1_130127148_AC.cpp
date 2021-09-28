/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1579/submission/130127148
 * Submitted at: 2021-09-29 00:07:17
 * Problem URL: https://codeforces.com/contest/1579/problem/E1
 * Result: AC
 * Execution Time: 295 ms
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

void solve() {
  int n;
  cin >> n;
  deque<int> dq;
  rep(i, n) {
    int p;
    cin >> p;
    if (dq.empty()) dq.push_back(p);
    else if (dq.front() > p)
      dq.push_front(p);
    else
      dq.push_back(p);
  }
  rep(i, n) {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}