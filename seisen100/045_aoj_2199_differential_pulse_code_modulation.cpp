#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll INF = 1000000000000000000LL;

int main() {
  while (true) {
    ll N, M;
    cin >> N >> M;
    if (N==0 && M==0) break;
    
    vector<ll> C(M), X(N+1);
    rep(i,0,M) cin >> C.at(i);
    rep(i,1,N+1) cin >> X.at(i);
    
    vector<vector<ll> > dp(N+1, vector<ll>(256, INF));
    vector<vector<bool> > act(N+1, vector<bool>(256, false));
    act.at(0).at(128) = true;
    dp.at(0).at(128) = 0;
    
    rep(i,1,N+1) {
      rep(j,0,256) {
        if (!act.at(i-1).at(j)) continue;
        rep(k,0,M) {
          if (j+C.at(k) <= 0) {
            dp.at(i).at(0) = min(dp.at(i).at(0), dp.at(i-1).at(j) + X.at(i)*X.at(i));
            act.at(i).at(0) = true;
          } else if (j+C.at(k) >= 255) {
            dp.at(i).at(255) = min(dp.at(i).at(255), dp.at(i-1).at(j) + (X.at(i)-255)*(X.at(i)-255));
            act.at(i).at(255) = true;
          } else {
            dp.at(i).at(j+C.at(k)) = min(dp.at(i).at(j+C.at(k)), dp.at(i-1).at(j) + (X.at(i) - (j+C.at(k))) * (X.at(i) - (j+C.at(k))));
            act.at(i).at(j+C.at(k)) = true;
          }
        }
      }
    }
    
    ll ans = INF;
    rep(i,0,256) ans = min(ans, dp.at(N).at(i));
    cout << ans << endl;
  }
  return 0;
}
