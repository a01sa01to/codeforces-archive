/*
 * Author: a01sa01to
 * Submission URL: https://codeforces.com/gym/103150/submission/120704409
 * Submitted at: 2021-06-27 12:33:32
 * Problem URL: https://codeforces.com/gym/103150/problem/E
 * Result: WA
 * Execution Time: 0 ms
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
    vector<int> a(100), b(100);
    loop(i,n){
      char c;
      cin >> c;
      a[c-'a']++;
    }
    loop(i,n){
      char c;
      cin >> c;
      b[c-'a']++;
    }
    int canChange = (b['o'-'a'] - a['o'-'a'])*3;
    loop(i,'z'-'a'+1){
      // cout << "[Debug] " << (char)('A'+i) << " " << a[i] << " " << b[i] << " " << canChange << endl;
      if(i == 'o'-'a'){ continue; }
      if(b[i] != a[i]){
        canChange -= abs(a[i] - b[i]);
        if(canChange < 0){
          break;
        }
      }
    }
    if(canChange < 0){
      cout << "NO" << endl;
    }
    else{
      cout << "YES" << endl;
    }
  }
  return 0;
}