#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

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

int main() {
  int N, M;
  cin >> N >> M;

  UnionFind uf(N);
  rep(i,0,M) {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    uf.unite(u, v);
  }

  set<pair<ll,ll>> st;
  int K;
  cin >> K;
  rep(i,0,K) {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    ll v1 = uf.root(x), v2 = uf.root(y);
    if (v1 > v2) swap(v1, v2);
    st.insert(make_pair(v1, v2));
  }

  int Q;
  cin >> Q;
  rep(i,0,Q) {
    ll p, q;
    cin >> p >> q;
    p--; q--;
    ll v1 = uf.root(p), v2 = uf.root(q);
    if (v1 > v2) swap(v1, v2);
    if (st.count(make_pair(v1, v2))) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}
