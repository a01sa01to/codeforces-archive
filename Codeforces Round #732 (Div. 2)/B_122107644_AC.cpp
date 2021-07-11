/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1546/submission/122107644
 * Submitted at: 2021-07-12 00:15:15
 * Problem URL: https://codeforces.com/contest/1546/problem/B
 * Result: AC
 * Execution Time: 233 ms
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
    vector<pair<string, ll2d>> a(n);
    vector<string> b(n - 1);
    ll2d ch(m, ll1d(26, 0));
    loop(i, n) {
      string s;
      cin >> s;
      ll2d c(m, ll1d(26, 0));
      loop(j, m) {
        c[j][s[j] - 'a']++;
        ch[j][s[j] - 'a']++;
      }
      a[i] = make_pair(s, c);
    }
    loop(i, n - 1) {
      string s;
      cin >> s;
      loop(j, m) {
        ch[j][s[j] - 'a']--;
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
        a[i].second.assign(m, { -1 });
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