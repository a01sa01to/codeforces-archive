/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1256/submission/127572672
 * Submitted at: 2021-09-01 14:18:17
 * Problem URL: https://codeforces.com/contest/1256/problem/C
 * Result: AC
 * Execution Time: 31 ms
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

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  ll1d c(m), sum(m + 1);
  rep(i, m) {
    cin >> c[i];
    sum[i + 1] += c[i] + sum[i];
  }
  if ((d - 1) * (m + 1) + sum[m] >= n) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
    return;
  }
  ll1d ans(n, 0);
  int j = 0, jmp = 1, len = 0;
  rep(i, n) {
    if (j == m) {
      ans[i] = 0;
    }
    else if (c[j] <= len) {
      j++;
      len = 0;
    }
    // これ以上飛ぶと重なる
    if (sum[m] - sum[j] >= n - i) {
      jmp = 1;
      ans[i] = j + 1;
      len++;
    }
    // これ以上飛ぶと落ちる
    else if (jmp >= d) {
      rep(k, c[j]) {
        ans[i] = j + 1;
        i++;
      }
      i--;
      j++;
      len = 0;
      jmp = 1;
    }
    // 飛べるところまで飛ぶ
    else if (jmp < d) {
      ans[i] = 0;
      jmp++;
    }
  }
  rep(i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  cout << fixed << setprecision(15);
  solve();
  return 0;
}