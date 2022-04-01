// (1) 最小全域木をクラスカル法で求める。この際、最小全域木を構成する辺をnew_edgesに格納しておく。（2で使う）
// (2) 最小全域木を構成する辺の中から、大きい順にK-1個取ってきて足し合わせる。これにより、K個の頂点を構成する最も値段が大きい木の構成が分かる。
// このK個の頂点のいずれかに対して、最小全域木を通って各頂点から移動させれば、移動料金が最安になる。
// 答えとしては、(1)の値から(2)の値を引けば良い。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef pair<int, pair<int,int> > Edge;

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
  int V, E, K;
  cin >> V >> E >> K;
  vector<Edge> edges(E);
  rep(i,0,E) {
    int s,t,w;
    cin >> s >> t >> w;
    s--;t--;
    edges.at(i) = Edge(w, make_pair(s,t));
  }
  
  sort(edges.begin(), edges.end());
  
  // (1)
  UnionFind UF(V);
  // 最小全域木の辺を格納する配列
  vector<Edge> new_edges = {};
  ll all_min = 0LL;
  rep(i,0,E) {
    Edge e = edges.at(i);
    int w = e.first;
    int u = e.second.first;
    int v = e.second.second;
    
    if (UF.issame(u,v)) continue;
    
    new_edges.push_back(e);
    all_min += w;
    UF.unite(u,v);
  }
  
  // (2)
  sort(new_edges.begin(), new_edges.end(), greater<Edge>());
  ll tmp = 0LL;
  rep(i,0,K-1) {
    tmp += new_edges.at(i).first;
  }
  
  cout << all_min - tmp << endl;
}
