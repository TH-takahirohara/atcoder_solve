#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

using Edge = pair<ll, vector<ll>>;

struct UnionFind {
  vector<int> par, siz;
  
  UnionFind(int n) : par(n,-1), siz(n,1) {}
  
  int root(int x) {
    if (par.at(x) == -1) return x;
    else return par.at(x) = root(par.at(x));
  }
  
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
  
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    
    if (x == y) return false;
    
    if (siz.at(x) < siz.at(y)) swap(x, y);
    
    par.at(y) = x;
    siz.at(x) += siz.at(y);
    return true;
  }
  
  int size(int x) {
    return siz.at(root(x));
  }
};

int main() {
  int N,M;
  cin >> N >> M;

  vector<Edge> edges(M);
  rep(i,0,M) {
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    edges.at(i) = Edge(c, {i,a,b});
  }

  sort(edges.begin(), edges.end());

  UnionFind uf(N);
  vector<bool> isInGraph(M);
  rep(i,0,M) {
    ll w = edges.at(i).first;
    ll idx = edges.at(i).second.at(0);
    ll u = edges.at(i).second.at(1);
    ll v = edges.at(i).second.at(2);

    if (uf.issame(u, v)) continue;

    isInGraph.at(idx) = true;
    uf.unite(u, v);
  }

  ll ans = 0;
  rep(i,0,M) {
    ll w = edges.at(i).first;
    ll idx = edges.at(i).second.at(0);
    if (!isInGraph.at(idx) && w > 0) ans += w;
  }
  cout << ans << endl;
}
