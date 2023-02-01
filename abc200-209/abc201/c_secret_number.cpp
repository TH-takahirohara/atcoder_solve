#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S;
  cin >> S;
  
  vector<bool> maru(10, false), batsu(10, false);
  
  rep(i,0,10) {
    if (S.at(i) == 'o') maru.at(i) = true;
    if (S.at(i) == 'x') batsu.at(i) = true;
  }
    
  int ans = 0;
  rep(i,0,10000) {
    int num = i;
    vector<bool> tmp(10, false);
    rep(j,0,4) {
      int keta = num % 10;
      tmp.at(keta) = true;
      num /= 10;
    }
    
    bool okmaru = true;
    rep(k,0,10) {
      if (maru.at(k) && !tmp.at(k)) okmaru = false;
    }
    bool okbatsu = true;
    rep(l,0,10) {
      if (batsu.at(l) && tmp.at(l)) okbatsu = false;
    }
    
    if (okmaru && okbatsu) ans++;
  }
  cout << ans << endl;
}

