/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/gym/102788/submission/136295162
 * Submitted at: 2021-11-21 09:09:01
 * Problem URL: https://codeforces.com/gym/102788/problem/A
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum(ll n) { return n * (n + 1) / 2; }
int main() {
  ll n;
  cin >> n;
  cout << sum(n * n) / n << endl;
  return 0;
}