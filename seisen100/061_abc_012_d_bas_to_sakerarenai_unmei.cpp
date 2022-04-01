#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const ll INF = 1LL << 60;

int main() {
  int V,E;
  cin >> V >> E;
  
  vector<vector<ll> > dp(V, vector<ll>(V, INF));
  rep(i,0,E) {
    int s,t;
    ll d;
    cin >> s >> t >> d;
    s--;t--;
    
    dp.at(s).at(t) = d;
    dp.at(t).at(s) = d;
  }
  
  rep(i,0,V) {
    dp.at(i).at(i) = 0;
  }
  
  rep(k,0,V) {
    rep(i,0,V) {
      rep(j,0,V) {
        dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k)+dp.at(k).at(j));
      }
    }
  }
  
  ll ans = INF;
  rep(i,0,V) {
    ll max_d = 0;
    rep(j,0,V) {
      if (dp.at(i).at(j) > max_d) max_d = dp.at(i).at(j);
    }
    if (ans > max_d) ans = max_d;
  }
  
  cout << ans << endl;
}
