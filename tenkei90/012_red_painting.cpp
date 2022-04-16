#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

struct UnionFind {
  vector<vector<pair<int,int>>> par;
  vector<vector<int>> siz;
  
  UnionFind(int h, int w) : par(h, vector<pair<int,int>>(w, make_pair(-1,-1))), siz(h, vector<int>(w, -1)) {}
  
  pair<int,int> root(int h, int w) {
    if (par.at(h).at(w) == make_pair(-1,-1)) return make_pair(h,w);
    else return par.at(h).at(w) = root(par.at(h).at(w).first, par.at(h).at(w).second);
  }
  
  bool issame(pair<int,int> x, pair<int,int> y) {
    return root(x.first, x.second) == root(y.first, y.second);
  }
  
  bool unite(pair<int,int> x, pair<int,int> y) {
    x = root(x.first, x.second); y = root(y.first, y.second);
    
    if (x == y) return false;
    
    if (siz.at(x.first).at(x.second) < siz.at(y.first).at(y.second)) swap(x, y);
    
    par.at(y.first).at(y.second) = x;
    siz.at(x.first).at(x.second) += siz.at(y.first).at(y.second);
    return true;
  }
  
  int size(int h, int w) {
    pair<int,int> r = root(h,w);
    return siz.at(r.first).at(r.second);
  }
};

int main() {
  int H,W,Q;
  cin >> H >> W >> Q;
  
  vector<vector<bool>> isred(H, vector<bool>(W, false));
  UnionFind uf(H,W);
  
  rep(iter, 0, Q) {
    int num;
    cin >> num;
    
    if (num==1) {
      int r,c;
      cin >> r >> c;
      r--;c--;
      
      isred.at(r).at(c) = true;
      rep(i,0,4) {
        int nr = r+dr.at(i);
        int nc = c+dc.at(i);
        if (nr>=0 && nr<H && nc>=0 && nc<W && isred.at(nr).at(nc)) {
          uf.unite(make_pair(r,c), make_pair(nr,nc));
        }
      }
    } else {
      int ra,ca,rb,cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;ca--;rb--;cb--;
      
      if (isred.at(ra).at(ca) && isred.at(rb).at(cb) && uf.issame(make_pair(ra,ca), make_pair(rb,cb))) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}
