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
  cin >> N;
  vector<ll> X(N), Y(N), Z(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i) >> Z.at(i);
  ll kahan = 0;
  rep(i,0,N) {
    kahan += Z.at(i);
  }
  kahan = kahan / 2 + 1;

  vector<vector<ll>> dp(900005, vector<ll>(N+1, 3e18));
  dp.at(0).at(0) = 0;

  rep(j,0,N) {
    rep(i,0,100001) {
      if (dp.at(i).at(j) > 2e18) continue;
      if (X.at(j) > Y.at(j)) { // 高橋派が多い
        dp.at(i+Z.at(j)).at(j+1) = min(dp.at(i+Z.at(j)).at(j+1), dp.at(i).at(j));
      } else { // 青木派が多い
        dp.at(i).at(j+1) = min(dp.at(i).at(j+1), dp.at(i).at(j));
        dp.at(i+Z.at(j)).at(j+1) = min(dp.at(i+Z.at(j)).at(j+1), dp.at(i).at(j) + ((X.at(j) + Y.at(j)) / 2 + 1 - X.at(j)));
      }
    }
  }

  ll ans = 3e18;
  rep(i,kahan,200000) {
    ans = min(ans, dp.at(i).at(N));
  }
  cout << ans << endl;
}
