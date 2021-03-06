#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef pair<double, pair<int,int> > Edge;

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
  while (true) {
    int N;
    cin >> N;
    if (N==0) break;
    
    vector<vector<double> > P(N, vector<double>(4));
    rep(i,0,N) {
      double x,y,z,r;
      cin >> x >> y >> z >> r;
      
      P.at(i).at(0) = x; P.at(i).at(1) = y; P.at(i).at(2) = z; P.at(i).at(3) = r;
      //P.at(i) = {x, y, z, r};
    }
    
    vector<Edge> edges;
    rep(i,0,N) {
      rep(j,i+1,N) {
        vector<double> v1, v2;
        v1 = P.at(i); v2 = P.at(j);
        double ctoc = sqrt((v1.at(0) - v2.at(0))*(v1.at(0) - v2.at(0)) + (v1.at(1) - v2.at(1))*(v1.at(1) - v2.at(1)) + (v1.at(2) - v2.at(2))*(v1.at(2) - v2.at(2)));
        double w = 0;
        if (ctoc - v1.at(3) - v2.at(3) > 0) w = ctoc - v1.at(3) - v2.at(3);
        
        Edge ne = Edge(w, make_pair(i,j));
        edges.push_back(ne);
        //edges.push_back({w, make_pair(i,j)});
      }
    }
    
    sort(edges.begin(), edges.end());
    
    UnionFind UF(N);
    
    double ans = 0.0;
    rep(i,0,edges.size()) {
      Edge e = edges.at(i);
      double w = e.first;
      int u = e.second.first;
      int v = e.second.second;
      
      if (UF.issame(u,v)) continue;
      
      ans += w;
      UF.unite(u,v);
    }
    
    cout << fixed << setprecision(3) << ans << endl;
  }
  return 0;
}
