#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef vector<vector<int>> Graph;
double PI = 3.14159265359;
ll MOD = 1000000007LL;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<long long> fact_inv, inv, Com;

/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(int n, int SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
    Com.resize(SIZE + 5);
    Com[0] = 1;
    for (int i = 1; i < SIZE + 5; i++) {
        Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
    }
}

/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(int k) {
    assert(!(k < 0));
    return Com[k];
}

ll INF = 1000000000000000LL;

int main() {
  ll H,N;
  cin >> H >> N;
  vector<ll> A(N), B(N);
  rep(i,0,N) cin >> A.at(i) >> B.at(i);
  
  vector<vector<ll>> dp(N+1, vector<ll>(H+1,INF));
  dp.at(0).at(0) = 0;
  
  rep(i,0,N) {
    rep(j,0,H+1) {
      if (j+A.at(i) <= H) dp.at(i).at(j+A.at(i)) = min(dp.at(i).at(j+A.at(i)), dp.at(i).at(j) + B.at(i));
      else dp.at(i).at(H) = min(dp.at(i).at(H), dp.at(i).at(j) + B.at(i));
      
      if (i==(N-1)) continue;
      
      dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j));

      if (j+A.at(i+1) <= H) dp.at(i+1).at(j+A.at(i+1)) = min(dp.at(i+1).at(j+A.at(i+1)), dp.at(i).at(j) + B.at(i+1));
      else dp.at(i+1).at(H) = min(dp.at(i+1).at(H), dp.at(i).at(j) + B.at(i+1));
    }
  }
  
  cout << dp.at(N-1).at(H) << endl;
}

