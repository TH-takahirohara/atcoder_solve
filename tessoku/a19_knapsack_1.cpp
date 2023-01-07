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
  int N, W;
  cin >> N >> W;
  vector<pair<int,ll>> vec(N);
  rep(i,0,N) {
    int w; ll v;
    cin >> w >> v;
    vec.at(i) = make_pair(w,v);
  }

  vector<vector<ll>> dp(N+1, vector<ll>(W+1, -1));
  dp.at(0).at(0) = 0;

  rep(i,0,N) {
    int w = vec.at(i).first;
    ll v = vec.at(i).second;
    rep(j,0,W+1) {
      if (dp.at(i).at(j) < 0) continue;
      dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(j));
      if (j+w <= W) dp.at(i+1).at(j+w) = max(dp.at(i+1).at(j+w), dp.at(i).at(j) + v);
    }
  }

  ll ans = 0;
  rep(j,0,W+1) ans = max(ans, dp.at(N).at(j));
  cout << ans << endl;
}
