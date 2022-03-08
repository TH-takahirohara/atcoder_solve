#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
const vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
int w, h;

void dfs(vector<vector<int>> &data, int h_now, int w_now) {
  // 訪れたところは0とする
  data.at(h_now).at(w_now) = 0;
  
  for (int i=0; i<8; i++) {
    int nw, nh;
    nw = w_now + dx.at(i);
    nh = h_now + dy.at(i);
        
    // 島の外の場合は飛ばす
    if (nw < 0 || nw >= w || nh < 0 || nh >= h) continue;
    if (data.at(nh).at(nw) == 0) continue;
    dfs(data, nh, nw);
  }
}

int main() {
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    
    vector<vector<int>> data(h, vector<int>(w, 0));
    
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        cin >> data.at(i).at(j);
      }
    }
    
    int cnt = 0;
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        if (data.at(i).at(j) == 0) continue;
        dfs(data, i, j);
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}
