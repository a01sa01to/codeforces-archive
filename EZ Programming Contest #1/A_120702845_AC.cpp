/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/gym/103150/submission/120702845
 * Submitted at: 2021-06-27 11:34:56
 * Problem URL: https://codeforces.com/gym/103150/problem/A
 * Result: AC
 * Execution Time: 467 ms
 */

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ull> ull1d;
typedef vector<ull1d> ull2d;
typedef vector<ull2d> ull3d;
#define loop(i,n) for(ull i=0;i<n;i++)
#define rloop(i,n) for(ll i=n-1;i>=0;i--)
#define all(vec) vec.begin(),vec.end()
template<class T> inline bool chmin(T& a,T b){ if(a>b){ a=b; return true;} return false; }
template<class T> inline bool chmax(T& a,T b){ if(a>b){ a=b; return true;} return false; }

int main(){ cout << fixed << setprecision(15);
  int t;
  cin >> t;
  loop(_,t){
    ull n,k;
    cin >> n >> k;
    ull1d a(n);
    loop(i,n){ cin >> a[i]; }
    cout << *max_element(all(a)) - *min_element(all(a)) << endl;
  }
  return 0;
}