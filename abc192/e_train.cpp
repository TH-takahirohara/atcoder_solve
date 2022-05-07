#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

//typedef vector<vector<int>> Graph;
double PI = 3.14159265359;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

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

struct Edge {
  ll to;
  ll t;
  ll k;
  Edge(ll to, ll t, ll k) : to(to), t(t), k(k) {}
};

typedef vector<vector<Edge> > Graph;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

ll INF = 1000000000000000000;

int main() {
  ll N,M,X,Y;
  cin>>N>>M>>X>>Y;
  X--;Y--;
  
  Graph G(N);
  rep(i,0,M) {
    ll a,b,t,k;
    cin>>a>>b>>t>>k;
    a--;b--;
    G.at(a).push_back(Edge(b,t,k));
    G.at(b).push_back(Edge(a,t,k));
  }
  
  vector<ll> times(N, INF);
  times.at(X) = 0;
  
  priority_queue<pair<ll,ll>,
                 vector<pair<ll,ll> >,
                 greater<pair<ll,ll> > > que;
  que.push(make_pair(0,X));
  while (!que.empty()) {
    ll v = que.top().second;
    ll ti = que.top().first;
    que.pop();
    
    if (times.at(v) < ti) continue;
    
    for (auto ne:G.at(v)) {
      ll nt;
      if (ti % ne.k != 0) nt = ne.k * (ti / ne.k + 1) + ne.t;
      else nt = ne.k * (ti / ne.k) + ne.t;
      if (chmin(times.at(ne.to), nt)) {
        que.push(make_pair(nt, ne.to));
      }
    }
  }
  if (times.at(Y) >= INF) cout << -1 << endl;
  else cout << times.at(Y) << endl;
}

