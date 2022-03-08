#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int w, h;
int D[100][100];

void dfs(int h_now, int w_now) {
  // 訪れたところは0とする
  D[h_now][w_now] = 0;
  
  for (int i=0; i<8; i++) {
    int nw, nh;
    nw = w_now + dx[i];
    nh = h_now + dy[i];
        
    // 島の外の場合は飛ばす
    if (nw < 0 || nw >= w || nh < 0 || nh >= h) continue;
    if (D[nh][nw] == 0) continue;
    dfs(nh, nw);
  }
}

int main() {
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    
    
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        cin >> D[i][j];
      }
    }
    
    int cnt = 0;
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        if (D[i][j] == 0) continue;
        dfs(i, j);
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}
