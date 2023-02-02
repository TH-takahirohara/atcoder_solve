#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

struct Edge {
  ll to;
  ll w;
  Edge(ll to, ll w) : to(to), w(w) {}
};

typedef vector<vector<Edge> > Graph;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

ll INF = 1000000000000000000;

int main() {
  ll N,M;
  cin>>N>>M;
  
  Graph G(N+1);
  // 「都市のペア」をキーとし、「道路番号」を値としてもつmap
  map<pair<int,int>,int> ma;
  
  rep(i,0,M) {
    ll a,b,w;
    cin>>a>>b>>w;
    //a--;b--;
    G.at(a).push_back(Edge(b,w));
    G.at(b).push_back(Edge(a,w));
    ma[make_pair(a,b)] = i+1;
    ma[make_pair(b,a)] = i+1;
  }
  
  vector<ll> dis(N+1, INF);
  vector<ll> bef_city(N+1);
  
  dis.at(1) = 0;
  
  priority_queue<pair<ll,ll>,
                 vector<pair<ll,ll> >,
                 greater<pair<ll,ll> > > que;
  que.push(make_pair(0,1));
  while (!que.empty()) {
    ll v = que.top().second;
    ll d = que.top().first;
    que.pop();
    
    if (dis.at(v) < d) continue;
    
    for (auto ne:G.at(v)) {
      
      if (chmin(dis.at(ne.to), dis.at(v) + ne.w)) {
        bef_city.at(ne.to) = v;
        que.push(make_pair(dis.at(v)+ne.w, ne.to));
      }
    }
  }
  
  rep(i,2,N+1) {
    if (i != N) cout << ma.at(make_pair(i, bef_city.at(i))) << " ";
    else cout << ma.at(make_pair(i, bef_city.at(i))) << endl;
  }
}

