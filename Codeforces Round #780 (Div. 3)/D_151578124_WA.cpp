/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1660/submission/151578124
 * Submitted at: 2022-04-01 01:23:25
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
  vector<int> minus(n + 1, 0);
  vector<int> zero(0);
  rep(i, n) minus[i + 1] = minus[i] + (a[i] < 0);
  rep(i, n) if (a[i] == 0) zero.push_back(i);
  Debug(minus, zero);
  if (zero.size() == 0) {
    if (minus[n] % 2 == 0) {
      printf("%d %d\n", 0, 0);
    }
    else {
      pair<int, int> l_coho(0, 0), r_coho(0, 0);
      for (int l = 0; l < n; l++) {
        if (abs(a[l]) == 2) l_coho.first++;
        if (a[l] < 0) {
          l_coho.second = l;
          break;
        }
      }
      for (int r = 0; r < n; r++) {
        if (abs(a[n - r - 1]) == 2) r_coho.first++;
        if (a[n - r - 1] < 0) {
          r_coho.second = r;
          break;
        }
      }
      Debug(l_coho, r_coho);
      if (l_coho < r_coho) {
        printf("%d %d\n", l_coho.second + 1, 0);
      }
      else {
        printf("%d %d\n", 0, r_coho.second + 1);
      }
    }
  }
  else {
    if ((minus[n] - minus[zero.back()]) % 2 == 0 && minus[zero[0] + 1] % 2 == 0) {
      int l = 0, r = 0;
      for (int i = 0; i < zero[0]; ++i)
        if (abs(a[i]) == 2) l++;
      for (int i = zero.back() + 1; i < n; ++i)
        if (abs(a[i]) == 2) r++;

      if (l < r) {
        printf("%d %d\n", zero.back() + 1, 0);
      }
      else {
        printf("%d %d\n", 0, n - zero[0]);
      }
    }
    else if (zero[0] > n - zero.back() - 1) {
      pair<int, int> l_coho(0, 0), r_coho(0, 0);
      for (int l = 0; l < zero[0]; l++) {
        if (abs(a[l]) == 2) l_coho.first++;
        if (a[l] < 0) {
          l_coho.second = l;
          break;
        }
      }
      for (int r = 0; r < zero[0]; r++) {
        if (abs(a[zero[0] - r - 1]) == 2) r_coho.first++;
        if (a[zero[0] - r - 1] < 0) {
          r_coho.second = r;
          break;
        }
      }
      Debug(l_coho, r_coho);
      if (l_coho < r_coho) {
        printf("%d %d\n", l_coho.second + 1, n - zero[0]);
      }
      else {
        printf("%d %d\n", 0, n - (zero[0] + r_coho.second - 1));
      }
    }
    else {
      pair<int, int> l_coho(0, 0), r_coho(0, 0);
      for (int l = 0; l + zero.back() + 1 < n; l++) {
        if (abs(a[l + zero.back() + 1]) == 2) l_coho.first++;
        if (a[l + zero.back() + 1] < 0) {
          l_coho.second = l;
          break;
        }
      }
      for (int r = 0; n - r - 1 > zero.back(); r++) {
        if (abs(a[n - r - 1]) == 2) r_coho.first++;
        if (a[n - r - 1] < 0) {
          r_coho.second = r;
          break;
        }
      }
      Debug(l_coho, r_coho);
      if (l_coho < r_coho) {
        printf("%d %d\n", l_coho.second + zero.back() + 2, 0);
      }
      else {
        printf("%d %d\n", zero.back() + 1, r_coho.second + 1);
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}