#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 998244353LL;

int main() {
  int N; cin >> N;
  vector<ll> A(N), B(N);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) cin >> B.at(i);

  vector<vector<ll>> dp(3005, vector<ll>(N));
  rep(i,A.at(0),B.at(0)+1) dp.at(i).at(0) = 1;
  rep(i,0,3000) {
    dp.at(i+1).at(0) += dp.at(i).at(0);
    dp.at(i+1).at(0) %= MOD;
  }

  rep(j,1,N) {
    rep(i,A.at(j),B.at(j)+1) {
      dp.at(i).at(j) += dp.at(i).at(j-1);
    }
    rep(i,0,3000) {
      dp.at(i+1).at(j) += dp.at(i).at(j);
      dp.at(i+1).at(j) %= MOD;
    }
  }
  cout << dp.at(3000).at(N-1) << endl;
}
