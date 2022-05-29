// 動的計画法+累積和で解き直した。（累積和の参考 https://qiita.com/drken/items/56a6b68edef8fc605821）
// 37行目で、累積和に対してMODを取っていくと当然だが誤った結果となるので注意。
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
  ll N,M,K;
  cin >> N >> M >> K;
  
  vector<ll> rui(M+1);
  rep(i,0,M+1) rui.at(i) = i;
  vector<vector<ll>> dp(N, vector<ll>(M, 0));
  rep(i,0,M) dp.at(0).at(i) = 1;
  
  rep(i,1,N) {
    rep(j,0,M) {
      ll tmp = 0;
      if (j-K >=0) tmp += rui.at(j-K+1) % MOD;
      if (j+K < M) {
        tmp += (rui.at(M) - rui.at(j+K)) % MOD;
        tmp %= MOD;
      }
      if (K==0) tmp -= dp.at(i-1).at(j);
      dp.at(i).at(j) = tmp % MOD;
    }
    
    rep(ite,1,M+1) {
      rui.at(ite) = (rui.at(ite-1) + dp.at(i).at(ite-1));
    }
  }
  
  cout << rui.at(M) % MOD;
}

