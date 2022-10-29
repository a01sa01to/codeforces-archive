/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/gym/103150/submission/120703961
 * Submitted at: 2021-06-27 12:17:31
 * Problem URL: https://codeforces.com/gym/103150/problem/D
 * Result: WA
 * Execution Time: 61 ms
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
    ull n,d;
    cin >> n >> d;
    double leastMove = sqrt((double)d);
    double maxiMove = sqrt(2.0) * n / 2;
    if(leastMove <= maxiMove){
      cout << "YES" << endl;
      for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        if(i <= n/2 && j <= n/2){
          cout << i << " " << j << " " << i+n/2 << " " << j+n/2 << endl;
        }
        else if(i <= n/2){
          cout << i << " " << j << " " << i+n/2 << " " << j-n/2 << endl;
        }
        else if(j <= n/2){
          cout << i << " " << j << " " << i-n/2 << " " << j+n/2 << endl;
        }
        else{
          cout << i << " " << j << " " << i-n/2 << " " << j-n/2 << endl;
        }
      }
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}