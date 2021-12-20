/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1619/submission/140037755
 * Submitted at: 2021-12-20 23:54:33
 * Problem URL: https://codeforces.com/contest/1619/problem/C
 * Result: AC
 * Execution Time: 61 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  string s, t;
  cin >> s >> t;
  stack<int> ans;
  while (!s.empty()) {
    int a = s.back() - '0';
    if (t.empty()) {
      cout << -1 << endl;
      return;
    }
    int b = t.back() - '0';
    s.pop_back(), t.pop_back();
    if (a <= b) ans.push(b - a);
    else {
      if (t.empty() || t.back() != '1') {
        cout << -1 << endl;
        return;
      }
      else {
        t.pop_back();
        b += 10;
        ans.push(b - a);
      }
    }
  }
  while (!t.empty()) {
    ans.push(t.back() - '0');
    t.pop_back();
  }
  ll outp = 0;
  while (!ans.empty()) {
    outp = outp * 10 + ans.top();
    ans.pop();
  }
  cout << outp << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}