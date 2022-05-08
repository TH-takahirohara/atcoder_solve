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

int main() {
  int N,Q;
  cin >>N>>Q;
  
  map<int,int> ltor;
  map<int,int> rtol;
  
  map<int,pair<int,int>> ma;
  
  rep(i,0,N+2) {
    ma[i] = make_pair(i-1,i+1);
  }
  
  rep(i,0,Q) {
    int x;
    cin>>x;
    //cout << x << endl;
    //cout << " sta " << endl;
    
    int pre = ma.at(x).first;
    int nex = ma.at(x).second;
    
    //cout << pre << " " << nex << endl;
    
    if (nex != N+1) {
      int nxnx = ma.at(nex).second;
      
      ma.at(pre) = make_pair(ma.at(pre).first, nex);
      ma.at(x) = make_pair(nex, nxnx);
      ma.at(nex) = make_pair(pre,x);
      ma.at(nxnx) = make_pair(x,ma.at(nxnx).second);
    } else {
      //cout << x << endl;
      //cout << pre << " " << nex << endl;
      int prpr = ma.at(pre).first;
      
      ma.at(x) = make_pair(prpr,pre);
      ma.at(pre) = make_pair(x,nex);
      
      ma.at(prpr) = make_pair(ma.at(prpr).first, x);
    }
  }
  
  ll sta = -1;
  rep(i,1,N+1) {
    if (ma.at(i).first == 0) sta = i;
  }
  
  ll now = 0;
  cout << sta << " ";
  rep(i,0,N-1) {
    if (i!=(N-2)) cout << ma.at(sta).second << " ";
    else cout << ma.at(sta).second;
    sta = ma.at(sta).second;
  }
}

