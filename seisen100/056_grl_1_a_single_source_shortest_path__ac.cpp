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
  int V,E,r;
  cin >> V >> E >> r;
  
  Graph G(V);
  rep(i,0,E) {
    int s,t,d;
    cin >> s >> t >> d;
    G.at(s).push_back(Edge(t,d));
  }
  
  vector<ll> dist(V, INF);
  dist.at(r) = 0;
  
  priority_queue<pair<ll,int>,
                 vector<pair<ll,int> >,
                 greater<pair<ll,int> > > que;
  que.push(make_pair(dist.at(r), r));
  
  while (!que.empty()) {
    int v = que.top().second;
    ll d = que.top().first;
    que.pop();
    
    if (d > dist.at(v)) continue;
    
    for (int ite=0; ite<G.at(v).size(); ite++) {
      Edge e = G.at(v).at(ite);
      if (chmin(dist.at(e.to), dist.at(v)+e.w)) {
        que.push(make_pair(dist.at(e.to), e.to));
      }
    }
  }
  
  rep(i,0,V) {
    if (dist.at(i) == INF) cout << "INF" << endl;
    else cout << dist.at(i) << endl;
  }
}
