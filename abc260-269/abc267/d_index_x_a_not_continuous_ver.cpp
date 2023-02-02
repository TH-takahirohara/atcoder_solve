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
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<vector<ll>> dp(M+1, vector<ll>(N+1, -1e18));
  dp.at(0).at(0) = 0;
  // dp.at(1).at(0) = A.at(0);
  rep(j,0,N) {
    rep(ite,0,M+1) {
      dp.at(ite).at(j+1) = max(dp.at(ite).at(j+1), dp.at(ite).at(j));
      if (ite < M) dp.at(ite+1).at(j+1) = max(dp.at(ite+1).at(j+1), dp.at(ite).at(j) + A.at(j)*(ite+1));
    }
  }
  
  cout << dp.at(M).at(N) << endl;
}
