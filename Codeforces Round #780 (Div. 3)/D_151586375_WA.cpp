/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1660/submission/151586375
 * Submitted at: 2022-04-01 01:44:26
 * Problem URL: https://codeforces.com/contest/1660/problem/D
 * Result: WA
 * Execution Time: 139 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
#ifdef LOCAL
  #include "settings/debug.cpp"
  #define _GLIBCXX_DEBUG
#else
  #define Debug(...) 0
#endif
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> zero(0);
  rep(i, n) if (a[i] == 0) zero.push_back(i);
  Debug(zero);
  if (zero.size() == 0) zero.push_back(n);
  vector<int> a1(0), a2(0);
  for (int i = 0; i < zero[0]; i++) a1.push_back(a[i]);
  for (int i = zero.back() + 1; i < n; i++) a2.push_back(a[i]);
  Debug(a1, a2);
  vector<int> s1(1, 1), s2(1, 1);
  rep(i, a1.size()) {
    int x = a1[i], y = s1.back();
    if (abs(x) == 2) {
      if (y < 0)
        y--;
      else
        y++;
    }
    if (x < 0) y *= -1;
    s1.push_back(y);
  }
  rep(i, a2.size()) {
    int x = a2[i], y = s2.back();
    if (abs(x) == 2) {
      if (y < 0)
        y--;
      else
        y++;
    }
    if (x < 0) y *= -1;
    s2.push_back(y);
  }
  Debug(s1, s2);
  int l1 = 0, r1 = s1.size() - 1;
  while (ll(s1.back()) * s1[l1] < 0) l1++;
  while (ll(s1[r1]) * s1[0] < 0) r1--;
  int l2 = 0, r2 = s2.size() - 1;
  while (ll(s2.back()) * s2[l2] < 0) l2++;
  while (ll(s2[r2]) * s2[0] < 0) r2--;

  vector<int> tmp = { abs(s1.back() - s1[l1]), abs(s1[r1] - s1[0]), abs(s2.back() - s2[l2]), abs(s2[r2] - s2[0]) };
  int i = max_element(tmp.begin(), tmp.end()) - tmp.begin();
  Debug(tmp, i);
  switch (i) {
    case 0:
      printf("%d %d\n", l1, n - zero[0]);
      break;
    case 1:
      printf("%d %d\n", 0, n - r1);
      break;
    case 2:
      printf("%d %d\n", zero.back() + l2 + 1, 0);
      break;
    case 3:
      printf("%d %d\n", zero.back() + 1, n - zero.back() - r2 + 1);
      break;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}