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
  int N,M;
  cin >> N >> M;
  
  vector<int> A(M),B(M);
  rep(i,0,M) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    A.at(i) = a; B.at(i) = b;
  }
  
  int ans = 0;
  rep(i,0,M) {
    UnionFind UF(N);
    int tar_a = A.at(i);
    int tar_b = B.at(i);
    rep(j,0,M) {
      if (i==j) continue;
      UF.unite(A.at(j),B.at(j));
    }
    if (!UF.issame(tar_a,tar_b)) ans++;
  }
  
  cout << ans << endl;
}
