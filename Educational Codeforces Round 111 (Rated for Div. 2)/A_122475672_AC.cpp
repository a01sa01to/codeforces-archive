/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1550/submission/122475672
 * Submitted at: 2021-07-15 00:08:40
 * Problem URL: https://codeforces.com/contest/1550/problem/A
 * Result: AC
 * Execution Time: 46 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  int t;
  cin >> t;
  loop(_, t) {
    int n;
    cin >> n;
    cout << ceil(sqrt(n)) << endl;
  }
  return 0;
}