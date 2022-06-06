// 079 操作順序によらない
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int R,C;
  cin >> R >> C;
  
  vector<vector<ll>> A(R, vector<ll>(C)), B(R, vector<ll>(C)), diff(R, vector<ll>(C));
  
  rep(i,0,R) rep(j,0,C) cin >> A.at(i).at(j);
  rep(i,0,R) rep(j,0,C) cin >> B.at(i).at(j);
  rep(i,0,R) rep(j,0,C) diff.at(i).at(j) = A.at(i).at(j) - B.at(i).at(j);
  
  ll ans = 0;
  rep(i,0,R-1) {
    rep(j,0,C-1) {
      ll tasu = -diff.at(i).at(j);
      diff.at(i).at(j) += tasu;
      diff.at(i+1).at(j) += tasu;
      diff.at(i).at(j+1) += tasu;
      diff.at(i+1).at(j+1) += tasu;
      ans += abs(tasu);
    }
  }
  
  bool can = true;
  rep(i,0,R) {
    rep(j,0,C) {
      if (diff.at(i).at(j) != 0) can = false;
    }
  }
  
  if (can) cout << "Yes" << endl << ans << endl;
  else cout << "No" << endl;
}

