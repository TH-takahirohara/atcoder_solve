#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 1000100000;
priority_queue<pair<int,int>,
                 vector<pair<int,int>>,
                 greater<pair<int,int>>> que;

struct Edge {
  int to;
  int w;
  Edge(int to, int w) : to(to), w(w) {}
};

typedef vector<vector<Edge>> Graph;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int N,M;
  cin >> N >> M;
  
  Graph G(N);
  rep(i,0,M) {
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    
    G.at(a).push_back(Edge(b,c));
    G.at(b).push_back(Edge(a,c));
  }
  
  vector<bool> used0(N, false), usedn(N, false);
  vector<int> dist0(N, INF), distn(N, INF);
  priority_queue<pair<int,int>,
                 vector<pair<int,int>>,
                 greater<pair<int,int>>> que;
  
  dist0.at(0) = 0;
  que.push(make_pair(dist0.at(0), 0));
  
  while (!que.empty()) {
    int v = que.top().second;
    int d = que.top().first;
    que.pop();
    
    if (d > dist0.at(v)) continue;
    
    for (auto e : G.at(v)) {
      if (chmin(dist0.at(e.to), dist0.at(v)+e.w)) {
        que.push(make_pair(dist0.at(e.to), e.to));
      }
    }
  }
  
  distn.at(N-1) = 0;
  que.push(make_pair(distn.at(N-1), N-1));
  
  while (!que.empty()) {
    int v = que.top().second;
    int d = que.top().first;
    que.pop();
    
    if (d > distn.at(v)) continue;
    
    for (auto e : G.at(v)) {
      if (chmin(distn.at(e.to), distn.at(v)+e.w)) {
        que.push(make_pair(distn.at(e.to), e.to));
      }
    }
  }
  
  rep(i,0,N) {
    cout << dist0.at(i) + distn.at(i) << endl;
  }
}
