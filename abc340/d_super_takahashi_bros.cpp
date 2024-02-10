#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

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
  int N;
  cin >> N;
  Graph G(N);
  rep(i,0,N-1) {
    int a,b,x;
    cin >> a >> b >> x;
    x--;
    G.at(i).push_back(Edge(i+1, a));
    G.at(i).push_back(Edge(x, b));
  }

  vector<ll> dist(N, 5e18);
  dist[0] = 0;
  priority_queue<pair<ll,int>,
                 vector<pair<ll,int> >,
                 greater<pair<ll,int> > > que;
  que.push(make_pair(dist[0], 0));

  while (!que.empty()) {
    int v = que.top().second;
    ll d = que.top().first;
    que.pop();

    if (d > dist.at(v)) continue;

    for (auto e : G.at(v)) {
      if (chmin(dist.at(e.to), dist.at(v) + e.w)) {
        que.push(make_pair(dist.at(e.to), e.to));
      }
    }
  }

  cout << dist.at(N-1) << endl;
}
