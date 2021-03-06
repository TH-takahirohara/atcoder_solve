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
    int s,t,d;
    cin >> s >> t >> d;
    dp.at(s).at(t) = d;
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
  
  rep(i,0,V) {
    if (dp.at(i).at(i) < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  
  rep(i,0,V) {
    rep(j,0,V) {
      if (dp.at(i).at(j) >= INF/2) cout << "INF";
      else cout << dp.at(i).at(j);
      if (j!=V-1) cout << " ";
    }
    cout << endl;
  }
}
