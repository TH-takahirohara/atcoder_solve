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
  int H,W;
  ll K,V;
  cin >> H >> W >> K >> V;
  
  vector<vector<ll>> A(H, vector<ll>(W, 0));
  rep(i,0,H) rep(j,0,W) cin >> A.at(i).at(j);
  
  vector<vector<ll>> vec(H+1, vector<ll>(W+1, 0));
  rep(i,0,H) rep(j,0,W) vec.at(i+1).at(j+1) = vec.at(i).at(j+1) + vec.at(i+1).at(j) - vec.at(i).at(j) + A.at(i).at(j);
  
  ll men = 0LL;
  rep(i,1,H+1) {
    rep(j,1,W+1) {
      rep(k,0,i) {
        rep(l,0,j) {
          ll tmp_men = (i-k)*(j-l);
          ll tochi = vec.at(i).at(j) - vec.at(k).at(j) - vec.at(i).at(l) + vec.at(k).at(l);
          ll house = tmp_men*K;
          if (tmp_men > men && tochi+house <= V) men = tmp_men;
        }
      }
    }
  }
  
  cout << men << endl;
}
