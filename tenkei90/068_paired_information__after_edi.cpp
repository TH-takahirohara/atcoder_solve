// 068 クエリ先読み／std::set
// 解説・解答コードを見た後に実装
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

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
  int N,Q;
  cin >> N >> Q;
  
  vector<ll> sum(N-1), A(N);
  vector<ll> T(Q), X(Q), Y(Q), V(Q);
  
  rep(i,0,Q) {
    ll t,x,y,v;
    cin>>t>>x>>y>>v;
    x--;y--;
    T.at(i) = t; X.at(i) = x; Y.at(i) = y; V.at(i) = v;
    if (t==0) {
      sum.at(x) = v;
    }
  }
  
  rep(i,0,N-1) {
    A.at(i+1) = sum.at(i) - A.at(i);
  }
  
  //rep(i,0,N) cout << A.at(i) << " ";
  
  UnionFind uf(N);
  rep(i,0,Q) {
    ll t,x,y,v;
    t=T.at(i); x=X.at(i); y=Y.at(i); v=V.at(i);
    if (t==0){
      uf.unite(x,y);
    } else {
      if (!uf.issame(x,y)) {
        cout << "Ambiguous" << endl;
      } else if (x%2 == y%2) {
        cout << A.at(y) + (v - A.at(x)) << endl;
      } else {
        cout << A.at(y) - (v - A.at(x)) << endl;
      }
    }
  }
}

