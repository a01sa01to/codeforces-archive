/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1546/submission/122079157
 * Submitted at: 2021-07-11 23:16:20
 * Problem URL: https://codeforces.com/contest/1546/problem/A
 * Result: AC
 * Execution Time: 30 ms
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
    vector<int> a(n), b(n), plus, minus;
    int sum = 0;
    loop(i, n) {
      cin >> a[i];
      sum += a[i];
    }
    loop(i, n) {
      cin >> b[i];
      sum -= b[i];
    }
    if (sum != 0) {
      cout << -1 << endl;
      continue;
    }
    loop(i, n) {
      if (a[i] - b[i] > 0) {
        loop(__, a[i] - b[i]) {
          minus.push_back(i + 1);
        }
      }
      else if (a[i] - b[i] < 0) {
        loop(__, b[i] - a[i]) {
          plus.push_back(i + 1);
        }
      }
    }
    cout << minus.size() << endl;
    loop(i, minus.size()) {
      cout << minus[i] << " " << plus[i] << endl;
    }
  }
  return 0;
}