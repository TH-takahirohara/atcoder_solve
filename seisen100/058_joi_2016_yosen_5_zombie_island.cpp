#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const ll INF = 1LL << 60;

struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};

typedef vector<vector<Edge> > Graph;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int V,E,K,S;
  cin >> V >> E >> K >> S;
  int p_nodan, p_dan;
  cin >> p_nodan >> p_dan;
  
  vector<bool> is_zom(V,false);
  rep(i,0,K) {
    int tmp;
    cin >> tmp;
    tmp--;
    is_zom.at(tmp) = true;
  }
  
  vector<vector<int>> G(V);
  rep(i,0,E) {
    int s,t;
    cin >> s >> t;
    s--;t--;
    G.at(s).push_back(t);
    G.at(t).push_back(s);
  }
  
  // ゾンビの町からの距離を格納
  vector<ll> dist_zom(V,INF);
  rep(i,0,V) {
    if (is_zom.at(i)) dist_zom.at(i) = 0;
  }
  
  priority_queue<pair<ll,int>,
                 vector<pair<ll,int> >,
                 greater<pair<ll,int> > > que;
  rep(i,0,V) {
    if (is_zom.at(i)) que.push(make_pair(dist_zom.at(i), i));
  }
  
  // 危険な町かどうかの判定
  vector<bool> is_dan(V, false);
  
  while (!que.empty()) {
    int v = que.top().second;
    ll d = que.top().first;
    que.pop();
    
    if (d > dist_zom.at(v)) continue;
    
    for (auto nv : G.at(v)) {
      if (chmin(dist_zom.at(nv), dist_zom.at(v)+1)) {
        que.push(make_pair(dist_zom.at(nv), nv));
      }
    }
  }
  
  // ゾンビの町から距離S以下の場合には危険な町とする。
  rep(i,0,V) {
    if (dist_zom.at(i) <= S && dist_zom.at(i) != 0) is_dan.at(i) = true;
  }
  
  // 宿泊費の計算を行う
  vector<ll> dist(V,INF);
  priority_queue<pair<ll,int>,
                 vector<pair<ll,int> >,
                 greater<pair<ll,int> > > que_2;
  dist.at(0) = 0;
  que_2.push(make_pair(dist.at(0), 0));
  
  
  
  while (!que_2.empty()) {
    int v = que_2.top().second;
    ll d = que_2.top().first;
    que_2.pop();
    
    if (d > dist.at(v)) continue;
    
    for (auto nv : G.at(v)) {
      if (is_zom.at(nv)) continue;
      if (nv == V-1) {
        chmin(dist.at(nv), dist.at(v));
        que_2.push(make_pair(dist.at(nv), nv));
      }
      int p = 0;
      if (is_dan.at(nv)) p = p_dan;
      else p = p_nodan;
      if (chmin(dist.at(nv), dist.at(v)+p)) {
        que_2.push(make_pair(dist.at(nv), nv));
      }
    }
  }
  
  cout << dist.at(V-1) << endl;
}
