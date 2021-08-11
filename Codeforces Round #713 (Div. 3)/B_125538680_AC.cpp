/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1512/submission/125538680
 * Submitted at: 2021-08-11 13:36:17
 * Problem URL: https://codeforces.com/contest/1512/problem/B
 * Result: AC
 * Execution Time: 31 ms
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
  int n;
  cin >> n;
  ll2d Grid(n, ll1d(n, 0));
  pair<ll, ll> a, b;
  bool found1 = false;
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, n) {
      if (s[j] == '*') {
        Grid[i][j] = 1;
        if (!found1) {
          a = { i, j };
          found1 = true;
        }
        else {
          b = { i, j };
        }
      }
    }
  }
  if (a.first == b.first && a.first != n - 1) {
    Grid[a.first + 1][a.second] = 1;
    Grid[b.first + 1][b.second] = 1;
  }
  else if (a.first == b.first) {
    Grid[a.first - 1][a.second] = 1;
    Grid[b.first - 1][b.second] = 1;
  }
  else if (a.second == b.second && a.second != n - 1) {
    Grid[a.first][a.second + 1] = 1;
    Grid[b.first][a.second + 1] = 1;
  }
  else if (a.second == b.second) {
    Grid[a.first][a.second - 1] = 1;
    Grid[b.first][a.second - 1] = 1;
  }
  else {
    Grid[a.first][b.second] = 1;
    Grid[b.first][a.second] = 1;
  }

  rep(i, n) {
    rep(j, n) {
      cout << (Grid[i][j] ? "*" : ".");
    }
    cout << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) { solve(); }
  return 0;
}