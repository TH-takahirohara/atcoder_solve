#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int> > graph;

int main() {
  int N;
  cin >> N;
  
  graph G(N);
  
  rep(i,0,N) {
    int u, k;
    cin >> u >> k;
    u--;
    
    rep(j,0,k) {
      int tmp;
      cin >> tmp;
      tmp--;
      G.at(u).push_back(tmp);
    }
  }
  
  vector<int> dist(N, -1);
  dist.at(0) = 0;
  
  queue<int> que;
  que.push(0);
  
  while (!que.empty()) {
    int now_v = que.front();
    que.pop();
    
    int next_arr_size = G.at(now_v).size();
    rep(i,0,next_arr_size) {
      int nx_v = G.at(now_v).at(i);
      if (dist.at(nx_v) == -1) {
        dist.at(nx_v) = dist.at(now_v) + 1;
        que.push(nx_v);
      }
    }
  }
  
  rep(i,0,N) {
    cout << i+1 << " " << dist.at(i) << endl;
  }
}
