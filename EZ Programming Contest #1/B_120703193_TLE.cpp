/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/gym/103150/submission/120703193
 * Submitted at: 2021-06-27 11:48:18
 * Problem URL: https://codeforces.com/gym/103150/problem/B
 * Result: TLE
 * Execution Time: 1500 ms
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
  int n,m;
  cin >> n >> m;
  ull2d a(n, ull1d(m));
  loop(i,n) loop(j,m){
    char c;
    cin >> c;
    switch(c){
    case '^':
      a[i][j] = 0;
      break;
    case 'v':
      a[i][j] = 1;
      break;
    case '<':
      a[i][j] = 2;
      break;
    case '>':
      a[i][j] = 3;
      break;
    }
  }
  ull ans = 0;
  while(true){
    bool cont = false;
    loop(i,n-1) loop(j,m){
      if(a[i][j] == 1 && a[i+1][j] == 0){
        ans++;
        a[i][j] = 0;
        a[i+1][j] = 1;
        cont = true;
      }
    }
    loop(i,n) loop(j,m-1){
      if(a[i][j] == 3 && a[i][j+1] == 2){
        ans++;
        a[i][j] = 2;
        a[i][j+1] = 3;
        cont = true;
      }
    }
    if(!cont){
      break;
    }
  }
  cout << ans << endl;
  return 0;
}