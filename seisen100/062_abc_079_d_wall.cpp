#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const ll INF = 1LL << 60;

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<vector<ll> > dp(10, vector<ll>(10, INF));
  rep(i,0,10) {
    rep(j,0,10) {
      cin >> dp.at(i).at(j);
    }
  }
  
  vector<vector<ll>> A(H, vector<ll>(W));
  rep(i,0,H) {
    rep(j,0,W) {
      cin >> A.at(i).at(j);
    }
  }
    
  rep(k,0,10) {
    rep(i,0,10) {
      rep(j,0,10) {
        dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k)+dp.at(k).at(j));
      }
    }
  }
  
  ll ans = 0;
  rep(i,0,H) {
    rep(j,0,W) {
      if (A.at(i).at(j) != -1 && A.at(i).at(j) != 1) ans += dp.at(A.at(i).at(j)).at(1);
    }
  }
  
  cout << ans << endl;
}
