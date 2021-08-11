/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1512/submission/125537789
 * Submitted at: 2021-08-11 13:20:26
 * Problem URL: https://codeforces.com/contest/1512/problem/A
 * Result: AC
 * Execution Time: 30 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

void solve() {
  int n, s1, s2, s3;
  cin >> n >> s1 >> s2 >> s3;
  if (s1 != s2 && s2 == s3) {
    cout << 1 << endl;
  }
  if (s1 != s2 && s1 == s3) {
    cout << 2 << endl;
  }
  if (s1 == s2 && s2 != s3) {
    cout << 3 << endl;
  }
  rep(i, n - 3) {
    int a;
    cin >> a;
    if (a != s1 && s1 == s2 && s2 == s3) {
      cout << i + 4 << endl;
    }
  }
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) { solve(); }
  return 0;
}