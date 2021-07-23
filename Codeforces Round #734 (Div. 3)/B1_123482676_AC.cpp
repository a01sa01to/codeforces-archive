/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1551/submission/123482676
 * Submitted at: 2021-07-24 00:14:16
 * Problem URL: https://codeforces.com/contest/1551/problem/B1
 * Result: AC
 * Execution Time: 15 ms
 */

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> ll1d;
typedef vector<ll1d> ll2d;

#define loop(i, n) for (ll i = 0; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  loop(_, t) {
    string s;
    cin >> s;
    if (s.size() < 2) {
      cout << 0 << endl;
      continue;
    }
    map<char, int> mp;
    loop(i, s.size()) {
      mp[s[i]]++;
    }
    ll ans = mp.size();
    loop(i, s.size()) {
      if (mp[s[i]] >= 2) {
        ans++;
        mp.erase(s[i]);
      }
    }
    ans /= 2;
    cout << ans << endl;
  }
  return 0;
}