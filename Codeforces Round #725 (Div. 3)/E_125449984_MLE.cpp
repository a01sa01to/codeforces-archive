/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1538/submission/125449984
 * Submitted at: 2021-08-10 15:43:30
 * Problem URL: https://codeforces.com/contest/1538/problem/E
 * Result: MLE
 * Execution Time: 1528 ms
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int countSubStr(string &s, string &p) {
  int cnt = 0;
  for (int i = 0; i + p.size() <= s.size(); i++) {
    if (s.substr(i, p.size()) == p) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  rep(_, t) {
    int n;
    cin >> n;
    map<string, string> mp;
    rep(i, n) {
      string inp, op;
      cin >> inp >> op;

      if (op == ":=") {
        string word;
        cin >> word;
        mp[inp] = word;
        // cout << word << endl;
      }
      else {
        string a, pls, b;
        cin >> a >> pls >> b;
        mp[inp] = mp[a] + mp[b];
        // cout << mp[inp] << endl;
      }
      if (i == n - 1) {
        string haha = "haha";
        cout << countSubStr(mp[inp], haha) << endl;
      }
    }
  }
  return 0;
}