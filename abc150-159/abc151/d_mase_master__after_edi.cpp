#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef vector<vector<int>> Graph;
double PI = 3.14159265359;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};

int H,W;
vector<string> S;
vector<vector<int>> idou;
vector<vector<bool>> seen;
queue<pair<int,int>> que;

int bfs(pair<int,int> sta) {
  que.push(sta);
  while (!que.empty()) {
    pair<int,int> p = que.front();
    que.pop();
    
    if (seen.at(p.first).at(p.second)) continue;
    
    seen.at(p.first).at(p.second) = true;
    
    rep(i,0,4) {
      int nr = p.first + dy.at(i);
      int nc = p.second + dx.at(i);
      
      if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
      if (seen.at(nr).at(nc)) continue;
      if (S.at(nr).at(nc) == '#') continue;
      idou.at(nr).at(nc) = idou.at(p.first).at(p.second) + 1;
      que.push(make_pair(nr,nc));
    }
  }
  
  int maxn = 0;
  rep(i,0,H) rep(j,0,W) maxn = max(maxn, idou.at(i).at(j));
  return maxn;
}

int main() {
  cin >> H >> W;
  
  S.assign(H, "");
  rep(i,0,H) cin >> S.at(i);
    
  int ans = 0;
  rep(i,0,H) {
    rep(j,0,W) {
      if (S.at(i).at(j) == '#') continue;
      idou.assign(H, vector<int>(W,0));
      seen.assign(H, vector<bool>(W,false));
      ans = max(ans, bfs(make_pair(i,j)));
    }
  }
  
  cout << ans << endl;
}

