/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/gym/103150/submission/120703548
 * Submitted at: 2021-06-27 12:02:56
 * Problem URL: https://codeforces.com/gym/103150/problem/C
 * Result: AC
 * Execution Time: 46 ms
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
    string s;
    cin >> s;
    vector<int> idx(4,-1);
    loop(i,s.size()){
      switch (s[i]){
        case 'e':
          idx[0] = i;
          break;
        case 'z':
          idx[1] = i;
          break;
        case 'p':
          idx[2] = i;
          break;
        case 'c':
          idx[3] = i;
          break;
        default:
          break;
      }
    }
    if(idx[3] < idx[2] || idx[2] < idx[1] || idx[3] < idx[1] || idx[3] < idx[0]){
      cout << "NO" << endl;
    }
    else{
      cout << "YES" << endl;
    }
  }
  return 0;
}