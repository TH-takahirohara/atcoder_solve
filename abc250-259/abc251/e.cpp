#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

double PI = 3.14159265359;

ll MOD = 1000000007LL;
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

// UnionFind
struct UnionFind {
  vector<ll> par, siz;
  
  UnionFind(ll n) : par(n,-1), siz(n,1) {}
  
  ll root(ll x) {
    if (par.at(x) == -1) return x;
    else return par.at(x) = root(par.at(x));
  }
  
  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }
  
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    
    if (x == y) return false;
    
    if (siz.at(x) < siz.at(y)) swap(x, y);
    
    par.at(y) = x;
    siz.at(x) += siz.at(y);
    return true;
  }
  
  ll size(ll x) {
    return siz.at(root(x));
  }
};

// 累乗
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll INF = 1000000000000000000LL;

int main() {
  ll N;
  cin>>N;
  vector<ll> A(N);
  rep(i,0,N) cin>>A.at(i);
  
  vector<ll> dp(N+1, INF);
  
  // A_1選択
  dp.at(0) = A.at(0);
  dp.at(1) = A.at(0);
  
  rep(i,0,N) {
    if (i+1 < N) {
      dp.at(i+1) = min(dp.at(i+1), dp.at(i)+A.at(i));
      dp.at(i+1) = min(dp.at(i+1), dp.at(i)+A.at(i+1));
    }
    
    if (i+2 < N) {
      dp.at(i+2) = min(dp.at(i+2), dp.at(i)+A.at(i+1));
    }
  }
  
  ll tmp = dp.at(N-1);
  
  // A_N選択
  //dp.assign(N, INF);
  vector<ll> dp2(N, INF);
  dp2.at(0) = A.at(N-1);
  
  rep(i,0,N-1) {
    if (i+1 < N-1) {
      dp2.at(i+1) = min(dp2.at(i+1), dp2.at(i)+A.at(i));
      dp2.at(i+1) = min(dp2.at(i+1), dp2.at(i)+A.at(i+1));
    }
    
    if (i+2 < N-1) {
      dp2.at(i+2) = min(dp2.at(i+2), dp2.at(i)+A.at(i+1));
    }
  }
  
  ll tmp2 = dp2.at(N-2);
  
  if (tmp < tmp2) cout << tmp << endl;
  else cout << tmp2 << endl;
}


