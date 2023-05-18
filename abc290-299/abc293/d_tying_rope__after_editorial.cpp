// 無向グラフのサイクル(閉路)の数を数える問題。
// 解説（文章）を読んだ後、サイクルの閉路検出の記事を見てから解いてAC。
// 参考: https://qiita.com/xryuseix/items/eb247016ea04a549c720
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

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

  UnionFind uf(2*N);
  rep(i,0,N) {
    uf.unite(i,i+N);
  }

  // 環状のロープの本数を求める。
  // 参考: https://qiita.com/xryuseix/items/eb247016ea04a549c720
  int kan = 0; // 環状のロープの本数
  rep(i,0,M) {
    int a, c;
    char b, d;
    cin >> a >> b >> c >> d;
    a--; c--;
    if (b == 'B') a += N;
    if (d == 'B') c += N;
    if (uf.issame(a,c)) {
      kan++;
    }
    uf.unite(a,c);
  }

  // ひとつながりになっているロープの総本数を求める。
  set<int> st_roots;
  int ropes = 0; // ひとつながりになっているロープの総本数
  rep(i,0,2*N) {
    if (!st_roots.count(uf.root(i))) ropes++;
    st_roots.insert(uf.root(i));
  }

  cout << kan << " " << ropes - kan << endl;
}
