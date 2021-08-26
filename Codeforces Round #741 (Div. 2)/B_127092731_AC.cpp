/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1562/submission/127092731
 * Submitted at: 2021-08-27 00:32:07
 * Problem URL: https://codeforces.com/contest/1562/problem/B
 * Result: AC
 * Execution Time: 389 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;
typedef pair<ll, ll> P;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

set<ll> prime;

bool chkPrime(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) { return false; }
  }
  return true;
}

void append(int num, set<ll>& found, priority_queue<P, vector<P>, greater<P>>& pq, int j) {
  if (!found.count(num)) {
    // cout << num << endl;
    if (!prime.count(num)) {
      pq.push({ num, j });
      found.insert(num);
    }
  }
}

void solve() {
  int k;
  string s;
  cin >> k >> s;
  priority_queue<P, vector<P>, greater<P>> pq;
  set<ll> found;
  for (int i = 0; i < k; i++) {
    string str = { s[i] };
    append(stoi(str), found, pq, 1);
    for (int j = i + 1; j < k; j++) {
      string str2 = { s[i], s[j] };
      append(stoi(str2), found, pq, 2);
      for (int l = j + 1; l < k; l++) {
        string str3 = { s[i], s[j], s[l] };
        append(stoi(str3), found, pq, 3);
      }
    }
  }
  P tp = pq.top();
  cout << tp.second << endl
       << tp.first << endl;
  return;
}

int main() {
  cout << fixed << setprecision(15);
  ll t;
  cin >> t;
  for (ll i = 2; i <= 1e4; i++) {
    if (chkPrime(i)) {
      prime.insert(i);
    }
  }
  while (t--) solve();
  return 0;
}