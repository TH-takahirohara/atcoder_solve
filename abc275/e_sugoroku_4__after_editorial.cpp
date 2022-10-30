// 確率をMODで表す問題
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

// 累乗を求める関数
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// 逆元を求める関数（フェルマーの小定理）
ll modinv(ll a, ll m) {
  return modpow(a, m-2, m);
}

int main() {
  int N,M,K;
  cin >> N >> M >> K;

  vector<vector<ll>> dp(K+1, vector<ll>(N+1));
  dp.at(0).at(0) = 1LL;

  ll inv = 1LL * modinv(M, MOD);

  rep(iter,0,K) {
    rep(i,0,N) {
      rep(j,1,M+1) {
        int nx = i + j;
        if (nx > N) nx = N - (nx - N);
        dp.at(iter+1).at(nx) += dp.at(iter).at(i) * inv;
        dp.at(iter+1).at(nx) %= MOD;
      }
    }
    dp.at(iter+1).at(N) += dp.at(iter).at(N);
    dp.at(iter+1).at(N) %= MOD;
  }

  cout << dp.at(K).at(N) << endl;
}
