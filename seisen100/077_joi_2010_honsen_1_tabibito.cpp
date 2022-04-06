#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> dis(N-1);
  vector<ll> idou(M);
  rep(i,0,N-1) cin >> dis.at(i);
  rep(i,0,M) cin >> idou.at(i);
  
  vector<ll> rui(N, 0);
  rep(i,0,N-1) rui.at(i+1) = rui.at(i) + dis.at(i);
  
  ll ans = 0;
  ll now = 0;
  rep(i,0,M) {
    ll cur, nx;
    cur = now;
    nx = cur + idou.at(i);
    
    if (cur > nx) ans += rui.at(cur) - rui.at(nx);
    else ans += rui.at(nx) - rui.at(cur);
    
    ans %= 100000;
    
    now += idou.at(i);
  }
  
  cout << ans << endl;
}

