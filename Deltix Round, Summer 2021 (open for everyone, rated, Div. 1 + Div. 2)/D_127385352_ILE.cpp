/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1556/submission/127385352
 * Submitted at: 2021-08-30 01:45:37
 * Problem URL: https://codeforces.com/contest/1556/problem/D
 * Result: ILE
 * Execution Time: 0 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  cout << fixed << setprecision(15);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  cout << "and " << 1 << " " << 2;
  fflush(stdout);
  int and12;
  cin >> and12;
  cout << "or " << 1 << " " << 2;
  fflush(stdout);
  int or12;
  cin >> or12;
  cout << "and " << 2 << " " << 3;
  fflush(stdout);
  int and23;
  cin >> and23;
  cout << "or " << 2 << " " << 3;
  fflush(stdout);
  int or23;
  cin >> or23;
  cout << "and " << 1 << " " << 3;
  fflush(stdout);
  int and13;
  cin >> and13;
  cout << "or " << 1 << " " << 3;
  fflush(stdout);
  int or13;
  cin >> or13;
  // A = (A or B) + (A or C) - (B or C) + (A and B) + (A and C)
  a[0] = ((or12 | or13) ^ or23) | and12 | and13;
  a[1] = ((or12 | or23) ^ or13) | and12 | and23;
  a[2] = ((or13 | or23) ^ or12) | and13 | and23;
  for (int i = 4; i <= n; i++) {
    cout << "and " << 1 << " " << i << endl;
    fflush(stdout);
    int andbit, orbit;
    cin >> andbit;
    cout << "or " << 1 << " " << i << endl;
    fflush(stdout);
    cin >> orbit;
    // A = (A or B) - B + (A and B)
    a[i - 1] = (orbit ^ a[0]) | andbit;
  }
  sort(all(a));
  cout << "finish " << a[--k] << endl;
  fflush(stdout);
  return 0;
}