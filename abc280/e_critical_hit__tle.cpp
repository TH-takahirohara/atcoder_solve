#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
  int N;
  ll P;
  cin >> N >> P;

  ll kaku2 = P * modinv(100, MOD) % MOD;
  ll kaku1 = (100 - P) * modinv(100, MOD) % MOD;
  // cout << kaku1 << " " << kaku2 << endl;

  vector<ll> dp(200005);
  dp.at(0) = 1;
  ll ans = 0;

  rep(i,0,N) {
    // rep(k,0,N+1) cout << dp.at(k) << " ";
    // cout << endl;
    vector<ll> dptmp(200005);
    rep(j,i,min(N, 2*i+1)) {
      dptmp.at(j+2) += dp.at(j) * kaku2;
      dptmp.at(j+2) %= MOD;
      dptmp.at(j+1) += dp.at(j) * kaku1;
      dptmp.at(j+1) %= MOD;
    }

    ans += dptmp.at(N) * (i+1);
    ans %= MOD;
    ans += dptmp.at(N+1) * (i+1);
    ans %= MOD;

    swap(dp, dptmp);
  }
  cout << ans << endl;
}
