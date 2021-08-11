/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1512/submission/125539392
 * Submitted at: 2021-08-11 13:49:55
 * Problem URL: https://codeforces.com/contest/1512/problem/C
 * Result: WA
 * Execution Time: 61 ms
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
  ll a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  ll n = s.size();
  rep(i, n) {
    if (s[i] == '0') { a--; }
    if (s[i] == '1') { b--; }
  }
  rep(i, n / 2) {
    ll j = n - i - 1;
    if (s[i] != s[j] && s[i] != '?' && s[j] != '?') {
      cout << -1 << endl;
      return;
    }
    else if (s[i] != s[j] && s[i] != '?') {
      s[j] = s[i];
      if (s[i] == '0') { a--; }
      if (s[i] == '1') { b--; }
    }
    else if (s[i] != s[j] && s[j] != '?') {
      s[i] = s[j];
      if (s[j] == '0') { a--; }
      if (s[j] == '1') { b--; }
    }
    else if (s[i] == s[j] && s[j] == '?') {
      if (a >= 2) {
        s[i] = '0';
        s[j] = '0';
        a -= 2;
      }
      else if (b >= 2) {
        s[i] = '1';
        s[j] = '1';
        b -= 2;
      }
      else {
        cout << -1 << endl;
        return;
      }
    }
  }
  if (a + b == 1) {
    s[n / 2] = (a ? '0' : '1');
    if (a) a--;
    else
      b--;
  }
  if (a < 0 || b < 0) {
    cout << -1 << endl;
  }
  else {
    cout << s << endl;
  }
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) { solve(); }
  return 0;
}