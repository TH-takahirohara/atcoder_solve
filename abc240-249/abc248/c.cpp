#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;

ll MOD = 998244353;

void add(ll &x, ll y) {
  x += y;
  x %= MOD;
}

int main() {
  ll N,M,K;
  cin >> N >> M >> K;
  
  vector<vector<vector<ll>>> dp(51, vector<vector<ll>>(51, vector<ll>(2501, 0)));
  
  rep(i,1,M+1) {
    dp.at(0).at(i).at(i) = 1;
  }
  
  rep(i,1,N) {
    rep(j,1,M+1) {
      rep(k,1,M+1) {
        rep(l,1,K+1) {
          if (dp.at(i-1).at(k).at(l) > 0 && l+j <= K) add(dp.at(i).at(j).at(l+j), dp.at(i-1).at(k).at(l));
        }
      }
    }
  }
  
  ll ans = 0;
  rep(i,0,M+1) {
    rep(j,0,K+1) {
      add(ans, dp.at(N-1).at(i).at(j));
    }
  }
  
  cout << ans << endl;
}
