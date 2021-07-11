/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1546/submission/122099694
 * Submitted at: 2021-07-11 23:55:40
 * Problem URL: https://codeforces.com/contest/1546/problem/B
 * Result: WA
 * Execution Time: 15 ms
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
    int n, m;
    cin >> n >> m;
    vector<pair<string, vector<int>>> a(n);
    vector<string> b(n - 1);
    vector<int> ch('z' - 'a', 0);
    loop(i, n) {
      string s;
      cin >> s;
      vector<int> c('z' - 'a', 0);
      loop(j, s.size()) {
        c[s[j] - 'a']++;
        ch[s[j] - 'a']++;
      }
      a[i] = make_pair(s, c);
    }
    loop(i, n - 1) {
      string s;
      cin >> s;
      loop(j, s.size()) {
        ch[s[j] - 'a']--;
      }
      b[i] = s;
    }
    sort(all(a));
    sort(all(b));
    char ini = a[n - 1].first[0];
    loop(i, n - 1) {
      if (a[i].first[0] != b[i][0]) {
        ini = a[i].first[0];
        break;
      }
    }
    loop(i, n) {
      if (a[i].first[0] != ini) {
        a[i].second.assign('z' - 'a', -1);
      }
    }
    loop(i, n) {
      if (a[i].second == ch) {
        cout << a[i].first << endl;
        fflush(stdout);
        break;
      }
    }
  }
  return 0;
}