// 例えばn:10,k:4の場合、下記の4つのケースが考えられる。
// (1) 4種類の値がある場合 (2) 3種類の値がある場合 (3) 2種類の値がある場合 (4) 1種類の値がある場合
// (3)について考えると、これは10種類から2種類を選ぶ場合の数(10 C 2)に対して3種類から1種類を選ぶ場合の数(3 C 1)をかければ良い。
// 後者については、例えば選んだ数が1と2である場合を考えると、1 2 2 2, 1 1 2 2, 1 1 1 2 のケースがあるが、
// これは3つの隙間から1と2を分かつ仕切りを1つ選ぶ場合の数に対応するので、K-1 C 1 となる。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const int MAX = 110000;
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
  COMinit();
  
  int N,K;
  cin >> N >> K;
  
  ll ans = 0;
  for (int i=K; i>=1; i--) {
    ans += (COM(N, i) * COM(K-1,i-1)) % MOD;
    ans %= MOD;
  }
  
  cout << ans << endl;
}
