// 本番中は、判定式をdoubleで書いていて3つWAを出した。解説後ACした。
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
double PI = 3.14159265359;
vector<int> dc = {1, 0, -1, 0};
vector<int> dr = {0, -1, 0, 1};

// 逆元を求める関数
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
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

// 累乗（の剰余）
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll nijou(ll x) {
  return x * x;
}


int main() {
  int N;
  cin >> N;
  
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  
  vector<ll> X(N), Y(N), R(N);
  rep(i,0,N) {
    cin >> X.at(i) >> Y.at(i) >> R.at(i);
  }
  
  vector<vector<int>> vec(N);
  
  rep(i,0,N) {
    rep(j,0,N) {
      if (i==j) continue;
      ll x1,y1,x2,y2,r1,r2;
      x1 = X.at(i); y1 = Y.at(i);
      x2 = X.at(j); y2 = Y.at(j);
      r1 = R.at(i); r2 = R.at(j);
      
      if (nijou(x1-x2) + nijou(y1-y2) > nijou(r1 + r2)) continue;
      if (nijou(x1-x2) + nijou(y1-y2) < nijou(r1 - r2)) continue;
      vec.at(i).push_back(j);
    }
  }
  
  int scir = -1, tcir = -1;
  rep(i,0,N) {
    ll x,y,r;
    x = X.at(i); y=Y.at(i); r = R.at(i);
    if (nijou(x-sx) + nijou(y-sy) == r*r) scir = i;
    if (nijou(x-tx) + nijou(y-ty) == r*r) tcir = i;
  }
    
  vector<bool> seen(N,false);
  stack<int> sta;
  
  seen.at(scir) = true;
  sta.push(scir);
  
  while (!sta.empty()) {
    int v = sta.top();
    sta.pop();
    
    for (auto nv : vec.at(v)) {
      if (seen.at(nv)) continue;
      seen.at(nv) = true;
      sta.push(nv);
    }
  }
  
  if (seen.at(tcir)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

