#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

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
  ll N,M;
  cin >> N >> M;
  
  vector<ll> A(M), B(M);
  rep(i,0,M) {
    ll a,b;
    cin >> a >> b;
    a--; b--;
    A.at(i) = a; B.at(i) = b;
  }
  
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  
  stack<ll> sta;
  ll ans = (ll)N * (N-1) / 2;
  sta.push(ans);
  
  UnionFind UF(N);
  rep(i,0,M-1) {
    ll a = A.at(i);
    ll b = B.at(i);
    
    if (UF.issame(a,b)) {
      sta.push(ans);
      continue;
    }
    
    ll size_a = UF.size(a);
    ll size_b = UF.size(b);
    
    ans -= (size_a * size_b);
    sta.push(ans);
    
    UF.unite(a,b);
  }
  
  rep(i,0,M) {
    cout << sta.top() << endl;
    sta.pop();
  }
}
