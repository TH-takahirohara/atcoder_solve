#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int R, C;

vector<int> dr = {1, 0, 0, -1};
vector<int> dc = {0, 1, -1, 0};

int main() {
  cin >> R >> C;
  
  vector<string> G(R);
  rep(i,0,R) {
    cin >> G.at(i);
  }
  
  // 最初の時点の白マスの個数
  int num_wh = 0;
  rep(i,0,R) {
    rep(j,0,C) {
      if (G.at(i).at(j) == '.') num_wh++;
    }
  }
  
  vector<vector<int>> dist(R, vector<int>(C, -1));
  queue<pair<int,int>> que;
  
  dist.at(0).at(0) = 1;
  que.push(make_pair(0,0));
  
  while (!que.empty()) {
    pair<int,int> np = que.front();
    que.pop();
    
    rep(i,0,4) {
      int nxr = np.first + dr.at(i);
      int nxc = np.second + dc.at(i);
      if (nxr < 0 || nxr >= R || nxc < 0 || nxc >= C) continue;
      if (G.at(nxr).at(nxc) == '#') continue;
      if (dist.at(nxr).at(nxc) != -1) continue;
      dist.at(nxr).at(nxc) = dist.at(np.first).at(np.second) + 1;
      que.push(make_pair(nxr,nxc));
    }
  }
  
  if (dist.at(R-1).at(C-1) == -1) {
    cout << -1 << endl;
  } else {
    cout << num_wh - dist.at(R-1).at(C-1) << endl;
  }
}
