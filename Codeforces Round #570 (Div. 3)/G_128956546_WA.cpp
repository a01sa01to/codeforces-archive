/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1183/submission/128956546
 * Submitted at: 2021-09-16 14:49:58
 * Problem URL: https://codeforces.com/contest/1183/problem/G
 * Result: WA
 * Execution Time: 264 ms
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

P add(P& ans, P& b) {
  return { ans.first + b.first, ans.second + b.first - b.second };
}

void solve() {
  int n;
  cin >> n;
  vector<P> cnt(n);
  rep(i, n) {
    int a, f;
    cin >> a >> f;
    cnt[--a].first++;
    if (f == 0) cnt[a].second++;
  }
  sort(all(cnt), [](P& a, P& b) {
    if (a.first > b.first) {
      return true;
    }
    else if (a.first == b.first) {
      return a.second < b.second;
    }
    return false;
  });
  // cout << "{ ";
  // for (P x : cnt) cout << "[ " << x.first << " " << x.second << "], ";
  // cout << " }" << endl;
  P ans = { cnt[0].first, cnt[0].first - cnt[0].second };
  rep(i, n) {
    // cout << "[DEB] " << ans.first << " " << ans.second << endl;
    if (i != 0) {
      if (cnt[i - 1].first <= 1) {
        break;
      }
      else if (cnt[i].first >= cnt[i - 1].first) {
        if (cnt[i].second < cnt[i - 1].first) {
          cnt[i].first = cnt[i - 1].first - 1;
          ans = add(ans, cnt[i]);
        }
      }
      else {
        ans = add(ans, cnt[i]);
      }
    }
  }
  cout << ans.first << " " << ans.second << endl;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) solve();
  // solve();
  return 0;
}
