#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N,M,K,S,T,X;
  cin >> N >> M >> K >> S >> T >> X;
  S--;T--;X--; // 0index
  
  vector<vector<ll>> G(N);
  
  rep(i,0,M) {
    ll tmp_u, tmp_v;
    cin >> tmp_u >> tmp_v;
    tmp_u--;tmp_v--;
    G.at(tmp_u).push_back(tmp_v);
    G.at(tmp_v).push_back(tmp_u);
  }
  
  vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(K+1, vector<ll>(2, 0)));
  
  dp.at(S).at(0).at(0) = 1;
  
  rep(j,0,K) {
    rep(i,0,N) {
      for (auto nv : G.at(i)) {
        if (nv != X) {
          dp.at(nv).at(j+1).at(0) += dp.at(i).at(j).at(0);
          dp.at(nv).at(j+1).at(1) += dp.at(i).at(j).at(1);
        } else {
          dp.at(nv).at(j+1).at(0) += dp.at(i).at(j).at(1);
          dp.at(nv).at(j+1).at(1) += dp.at(i).at(j).at(0);
        }
        dp.at(nv).at(j+1).at(0) %= 998244353;
        dp.at(nv).at(j+1).at(1) %= 998244353;
      }
    }
  }
  
  cout << dp.at(T).at(K).at(0) << endl;
}
