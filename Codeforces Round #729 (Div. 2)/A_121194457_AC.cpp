/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/contest/1542/submission/121194457
 * Submitted at: 2021-07-03 22:09:03
 * Problem URL: https://codeforces.com/contest/1542/problem/A
 * Result: AC
 * Execution Time: 31 ms
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
    int n;
    cin >> n;
    int c = 0;
    loop(i,2*n){
      int a;
      cin >> a;
      c += a%2;
    }
    if(c==n){ cout << "Yes" << endl; }
    else{ cout << "No" << endl; }
  }
  return 0;
}