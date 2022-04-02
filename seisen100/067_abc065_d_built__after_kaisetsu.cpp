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
  int N;
  cin >> N;
  
  vector<vector<int>> dots(N);
  vector<vector<int>> dots_y(N);
  rep(i,0,N) {
    int x,y;
    cin >> x >> y;
    dots.at(i) = {x,y,i};
    dots_y.at(i) = {y,x,i};
  }
  
  sort(dots.begin(), dots.end());
  sort(dots_y.begin(), dots_y.end());
  
  vector<Edge> edges;
  rep(i,0,N-1) {
    edges.push_back({dots.at(i+1).at(0) - dots.at(i).at(0), make_pair(dots.at(i+1).at(2), dots.at(i).at(2))});
    edges.push_back({dots_y.at(i+1).at(0) - dots_y.at(i).at(0), make_pair(dots_y.at(i+1).at(2), dots_y.at(i).at(2))});
  }
  
  sort(edges.begin(), edges.end());
  
  UnionFind UF(N);
  
  ll ans = 0LL;
  rep(i,0,edges.size()) {
    Edge e = edges.at(i);
    int w = e.first;
    int u = e.second.first;
    int v = e.second.second;
    
    if (UF.issame(u,v)) continue;
    
    ans += w;
    UF.unite(u,v);
  }
  
  cout << ans << endl;
}
