#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

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
  int N,Q;
  cin >> N >> Q;
  
  UnionFind UF(N);
  
  rep(i,0,Q) {
    int com;
    cin >> com;
    int x,y;
    cin >> x >> y;
    
    if (com==0) {
      UF.unite(x,y);
    } else {
      if (UF.issame(x,y)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
}
