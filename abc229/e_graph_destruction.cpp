// 考え方は合っていたが、kの値の決め方が不適切で解けなかった。
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

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

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i,0,M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
  }

  vector<int> vec = {0};
  UnionFind uf = UnionFind(N);
  int ans = 0;
  for (int i=N-1; i >= 1; i--) {
    ans++;
    for (auto nv : G.at(i)) {
      if (uf.issame(i, nv)) continue;
      ans--;
      uf.unite(i, nv);
    }
    vec.push_back(ans);
  }

  rep(i,0,vec.size()) {
    cout << vec.at(vec.size() - i - 1) << endl;
  }
}
