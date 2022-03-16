// 考え方：内側の0なのか、外側の0なのかが知りたい。外周に沿って配置されている0に対して
// 幅優先探索を実行し、外側から繋がっている0なのかどうかのbool値を割り当てるようにする。
// そして、1の周囲の数値を順番に見て、隣接しかつ外部に位置する0の場合にはイルミネーションを施すので、
// カウントするようにする。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<int> dr_od = {-1, -1, 0, 1, 1, 0};
vector<int> dc_od = {-1, 0, 1, 0, -1, -1};
vector<int> dr_ev = {-1, -1, 0, 1, 1, 0};
vector<int> dc_ev = {0, 1, 1, 1, 0, -1};
int C, R;

void bfs_zero(int i, int j, queue<pair<int,int>> &que_z, vector<vector<int>> &G, vector<vector<bool>> &inside_zero) {
  if (G.at(i).at(j) == 0 && inside_zero.at(i).at(j)) {
    inside_zero.at(i).at(j) = false;
    que_z.push(make_pair(i, j));
    while (!que_z.empty()) {
      pair<int,int> now_p = que_z.front();
      que_z.pop();
      
      rep(k,0,6) {
        int nxr, nxc;
        if (now_p.first % 2 == 0) {
          nxr = now_p.first + dr_ev.at(k);
          nxc = now_p.second + dc_ev.at(k);
        } else {
          nxr = now_p.first + dr_od.at(k);
          nxc = now_p.second + dc_od.at(k);
        }
        if (nxr < 0 || nxr >= R || nxc < 0 || nxc >= C) continue;
        if (G.at(nxr).at(nxc) == 1) continue;
        if (G.at(nxr).at(nxc) == 0 && !inside_zero.at(nxr).at(nxc)) continue;
        inside_zero.at(nxr).at(nxc) = false;
        que_z.push(make_pair(nxr, nxc));
      }
    }
  }
}

int main() {
  cin >> C >> R;
  
  vector<vector<int> > G(R, vector<int>(C, 0));
  rep(i,0,R) {
    rep(j,0,C) {
      cin >> G.at(i).at(j);
    }
  }
  
  // 0が内側の0かどうかを判定する
  vector<vector<bool> > inside_zero(R, vector<bool>(C, true));
  queue<pair<int, int> > que_z;
  // 上端と下端のみ走査
  for (int i=0; i<R; i+=(R-1)) {
    for (int j=0; j<C; j++) {
      bfs_zero(i, j, que_z, G, inside_zero);
    }
  }
  // 左端と右端のみ走査
  for (int j=0; j<C; j+=(C-1)) {
    for (int i=0; i<R; i++) {
      bfs_zero(i, j, que_z, G, inside_zero);
    }
  }
  
  int ans = 0;
  queue<pair<int,int>> que;
  rep(i,0,R) {
    rep(j,0,C) {
      int tmp_len = 0;
      if (G.at(i).at(j) == 0) continue;
      
      rep(k,0,6) {
        int nxr, nxc;
        if (i % 2 == 0) {
          nxr = i + dr_ev.at(k);
          nxc = j + dc_ev.at(k);
        } else {
          nxr = i + dr_od.at(k);
          nxc = j + dc_od.at(k);
        }
        // 端の場合加算（装飾）する
        if (nxr < 0 || nxr >= R || nxc < 0 || nxc >= C) {
          tmp_len++;
          continue;
        }
        // 隣接するマスが0で、かつ内部ではない場合、加算する
        if (G.at(nxr).at(nxc) == 0 && !inside_zero.at(nxr).at(nxc)) tmp_len++;
      }
      ans += tmp_len;
    }
  }
  
  cout << ans << endl;
}
