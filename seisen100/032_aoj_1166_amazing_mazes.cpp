#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int R, C;

int main() {
  while (true) {
    // 入力
    cin >> C >> R;
    if (C == 0 && R == 0) break;

    vector<vector<int> > yoko(R-1, vector<int>(C));
    vector<vector<int> > tate(R, vector<int>(C-1));

    rep(i,0,(2*R-1)) {
      if (i % 2 == 0) {
        rep(j,0,C-1) cin >> tate.at(i/2).at(j);
      } else {
        rep(j,0,C) cin >> yoko.at(i/2).at(j);
      }
    }
    
    // 幅優先探索
    vector<vector<int> > dist(R, vector<int>(C, -1));
    queue<pair<int,int> > que;
    
    dist.at(0).at(0) = 1;
    que.push(make_pair(0,0));
    while (!que.empty()) {
      pair<int,int> now_p = que.front();
      que.pop();
      
      rep(i,0,4) {
        int nxr, nxc;
        int nr = now_p.first; int nc = now_p.second;
        if (i==0) {
          // 一つ上
          nxr = nr-1; nxc = nc;
          if (nxr < 0 || nxr >= R-1 || nxc < 0 || nxc >= C) continue;
          if (yoko.at(nxr).at(nxc) == 1) continue;
          if (dist.at(nr-1).at(nc) != -1) continue;
          dist.at(nr-1).at(nc) = dist.at(nr).at(nc) + 1;
          que.push(make_pair(nr-1, nc));
        } else if (i==1) {
          // 一つ下
          if (nr < 0 || nr >= R-1 || nc < 0 || nc >= C) continue;
          if (yoko.at(nr).at(nc) == 1) continue;
          if (dist.at(nr+1).at(nc) != -1) continue;
          dist.at(nr+1).at(nc) = dist.at(nr).at(nc) + 1;
          que.push(make_pair(nr+1, nc));
        } else if (i==2) {
          // 一つ左
          nxr = nr; nxc = nc-1;
          if (nxr < 0 || nxr >= R || nxc < 0 || nxc >= C-1) continue;
          if (tate.at(nxr).at(nxc) == 1) continue;
          if (dist.at(nr).at(nc-1) != -1) continue;
          dist.at(nr).at(nc-1) = dist.at(nr).at(nc) + 1;
          que.push(make_pair(nr, nc-1));
        } else if (i==3) {
          // 一つ右
          if (nr < 0 || nr >= R || nc < 0 || nc >= C-1) continue;
          if (tate.at(nr).at(nc) == 1) continue;
          if (dist.at(nr).at(nc+1) != -1) continue;
          dist.at(nr).at(nc+1) = dist.at(nr).at(nc) + 1;
          que.push(make_pair(nr, nc+1));
        }
      }
    }
    
    if (dist.at(R-1).at(C-1) == -1) cout << 0 << endl;
    else cout << dist.at(R-1).at(C-1) << endl;
  }
}
