#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
typedef vector<vector<ll>> graph;

ll N, Q;
vector<ll> cnts;
vector<ll> pas;
vector<ll> matome;

// 各値の親を確定させるための再帰関数
void p_dfs(graph &G, ll v, ll p) {
  pas.at(v) = p;
  for (auto nv : G.at(v)) {
    if (nv == p) continue;
    p_dfs(G, nv, v);
  }
}

// カウンタを更新するための再帰関数
// cntにmatome配列でまとめた値を足して次に渡す。こうすることで、一度の深さ優先探索で一気に計算できる。
void dfs(graph &G, ll v, ll p, ll cnt=0LL) {
  cnt += matome.at(v);
  cnts.at(v) += cnt;
  for (auto nv : G.at(v)) {
    if (nv == p) continue;
    dfs(G, nv, v, cnt);
  }
}

int main() {
  cin >> N >> Q;
  
  graph G(N+1);
  cnts.assign(N+1, 0);
  pas.assign(N+1, -1);
  
  rep(i,0,N-1) {
    ll A, B;
    cin >> A >> B;
    G.at(A).push_back(B);
    G.at(B).push_back(A);
  }
  
  p_dfs(G, 1, -1);
  
  // 同じPの場合の加算するXを足し合わせた配列を作る
  matome.assign(N+1, 0);
  rep(i,0,Q) {
    ll P, X;
    cin >> P >> X;
    matome.at(P) += X;
  }
  
  dfs(G, 1, -1);
    
  rep(i,1,N+1) {
    if (i != N) cout << cnts.at(i) << " ";
    else cout << cnts.at(i) << endl;
  }
}
