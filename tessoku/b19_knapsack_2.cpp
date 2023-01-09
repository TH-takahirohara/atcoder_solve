#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  ll W;
  cin >> N >> W;
  vector<pair<ll,int>> vec(N);
  rep(i,0,N) {
    ll w;
    int v;
    cin >> w >> v;
    vec.at(i) = make_pair(w,v);
  }

  vector<vector<ll>> dp(N+1, vector<ll>(1000005, 1e18));
  dp.at(0).at(0) = 0;

  rep(i,0,N) {
    ll w = vec.at(i).first;
    int v = vec.at(i).second;
    rep(j,0,1000001) {
      if (dp.at(i).at(j) < 0) continue;
      dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j));
      if (j+v <= 1000000) dp.at(i+1).at(j+v) = min(dp.at(i+1).at(j+v), dp.at(i).at(j) + w);
    }
  }

  ll ans = 0;
  rep(j,0,1000001) {
    if (dp.at(N).at(j) <= W) ans = max(ans, (ll)j);
  }
  cout << ans << endl;
}
