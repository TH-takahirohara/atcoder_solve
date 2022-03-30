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
  int N,K;
  cin >> N >> K;
  
  Graph G(N);
  
  rep(iter,0,K) {
    int ch;
    cin >> ch;
    if (ch == 1) {
      // 運行情報の追加
      int s,t,d;
      cin >> s >> t >> d;
      s--;t--;
      G.at(s).push_back(Edge(t,d));
	  G.at(t).push_back(Edge(s,d));
    } else {
      int s,t;
      cin >> s >> t;
      s--;t--;
      
      vector<bool> used(N, false);
      vector<ll> dist(N, INF);
      dist.at(s) = 0;
      
      rep(ite,0,N) {
        // 最小の距離の探索
        int min_v = -1;
        ll min_dist = INF;
        rep(i,0,N) {
          if (!used.at(i) && dist.at(i) < min_dist) {
            min_v = i;
            min_dist = dist.at(i);
          }
        }
        
        if (min_v == -1) break;
        
        for (auto e : G.at(min_v)) {
          chmin(dist.at(e.to), dist.at(min_v) + e.w);
        }
        used.at(min_v) = true;
      }
      
      if (dist.at(t) == INF) cout << -1 << endl;
      else cout << dist.at(t) << endl;
    }
  }
}
