#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

double PI = 3.14159265359;

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
  queue<pair<ll,ll>> que;
  int Q;
  cin >> Q;
  
  rep(i,0,Q) {
    int han;
    cin >> han;
    
    if (han==1) {
      ll x,c;
      cin >> x >> c;
      que.push(make_pair(x,c));
    } else {
      ll c;
      cin >> c;
      
      ll ans = 0LL;
      while (c > 0) {
        if (que.size()==0) break;
        
        pair<ll,ll> pa = que.front();
        if (c == pa.second) {
          ans += que.front().first * que.front().second;
          que.pop();
          break;
        } else if (c < pa.second) {
          que.front().second -= c;
          ans += que.front().first * c;
          break;
        } else {
          ans += que.front().first * que.front().second;
          c -= que.front().second;
          que.pop();
        }
      }
      
      cout << ans << endl;
    }
  }
}
