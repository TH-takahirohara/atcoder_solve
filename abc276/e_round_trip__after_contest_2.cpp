// UnionFindを使った解答
// 2次元の場合はUnionFindの要素数をR*Cとし、C*r+cを要素の番号とする。
// （最初、R*r+cとしていて間違えており、デバッグに苦労したので注意。）
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<int> dc = {1, 0, -1, 0};
vector<int> dr = {0, -1, 0, 1};

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
  int R, C;
  cin >> R >> C;
  vector<string> vec(R);
  rep(i,0,R) cin >> vec.at(i);

  UnionFind uf(R*C);
  int r0, c0;
  rep(r,0,R) {
    rep(c,0,C) {
      if (vec.at(r).at(c) == '#') continue;
      if (vec.at(r).at(c) == 'S') {
        r0 = r; c0 = c;
        continue;
      }
      rep(i,0,4) {
        int nr = r + dr.at(i);
        int nc = c + dc.at(i);
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (vec.at(nr).at(nc) == '#' || vec.at(nr).at(nc) == 'S') continue;
        if (uf.issame(C*r+c, C*nr+nc)) continue;
        uf.unite(C*r+c, C*nr+nc);
      }
    }
  }

  vector<pair<int,int>> nexts;
  rep(i,0,4) {
    int nr = r0 + dr.at(i);
    int nc = c0 + dc.at(i);
    if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
    if (vec.at(nr).at(nc) == '#') continue;
    nexts.push_back(make_pair(nr,nc));
  }

  bool ans = false;
  rep(i,0,nexts.size()) {
    rep(j,i+1,nexts.size()) {
      int r1 = nexts.at(i).first;
      int c1 = nexts.at(i).second;
      int r2 = nexts.at(j).first;
      int c2 = nexts.at(j).second;
      if (uf.issame(C*r1+c1, C*r2+c2)) ans = true;
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
