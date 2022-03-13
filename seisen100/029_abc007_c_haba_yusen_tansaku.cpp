#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<int> dr = {1, 0, 0, -1};
vector<int> dc = {0, 1, -1, 0};

int main() {
  int R, C;
  cin >> R >> C;
  
  int sr, sc, gr, gc;
  cin >> sr >> sc >> gr >> gc;
  sr--; sc--; gr--; gc--;
  
  vector<string> G(R);
  rep(i,0,R) cin >> G.at(i);
  
  vector<vector<int> > dist(R, vector<int>(C, -1));
  
  queue<pair<int, int>> que;
  dist.at(sr).at(sc) = 0;
  que.push(make_pair(sr, sc));
  while (!que.empty()) {
    pair<int,int> now_p = que.front();
    que.pop();
    
    rep(i,0,4) {
      int nr = now_p.first + dr.at(i);
      int nc = now_p.second + dc.at(i);
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      if (G.at(nr).at(nc) == '#') continue;
      if (dist.at(nr).at(nc) != -1) continue;
      dist.at(nr).at(nc) = dist.at(now_p.first).at(now_p.second) + 1;
      que.push(make_pair(nr, nc));
    }
  }
  
  cout << dist.at(gr).at(gc) << endl;
}
