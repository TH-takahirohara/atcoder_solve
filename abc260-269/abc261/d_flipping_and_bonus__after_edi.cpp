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
  int N,M;
  cin >> N >> M;
  vector<ll> X(N);
  rep(i,0,N) cin >> X.at(i);
  vector<ll> C(5005);
  rep(i,0,M) {
    ll c, y;
    cin >> c >> y;
    C.at(c) = y;
  }

  vector<vector<ll>> dp(N+1, vector<ll>(N+1, -8e18));
  dp.at(0).at(0) = 0;
  rep(i,0,N) {
    rep(j,0,N) {
      if (dp.at(i).at(j) >= 0) {
        dp.at(i+1).at(j+1) = dp.at(i).at(j) + X.at(i) + C.at(j+1);
        dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(j));
      }
    }
  }

  ll ans = 0;
  rep(j,0,N+1) ans = max(ans, dp.at(N).at(j));
  cout << ans << endl;
}
