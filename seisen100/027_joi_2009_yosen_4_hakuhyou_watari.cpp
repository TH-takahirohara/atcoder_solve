#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
typedef vector<vector<int>> graph;

// C: 列数、 R: 行数
int C, R;
int max_cnt = 0;

vector<int> dr = {1, 0, 0, -1};
vector<int> dc = {0, -1, 1, 0};

void dfs(graph G, int row, int col, int cnt=0) {
  cnt++;
  max_cnt = max(max_cnt, cnt);
  G.at(row).at(col) = 0;
  
  rep(i,0,4) {
    if (row+dr.at(i) < 0 || row+dr.at(i) >= R || col+dc.at(i) < 0 || col+dc.at(i) >= C) continue;
    if (G.at(row+dr.at(i)).at(col+dc.at(i)) == 0) continue;
    dfs(G, row+dr.at(i), col+dc.at(i), cnt);
  }
}

int main() {
  cin >> C >> R;
  
  graph G(R, vector<int>(C, 0));
  
  rep(i,0,R) {
    rep(j,0,C) {
      cin >> G.at(i).at(j);
    }
  }
  
  int ans = 0;
  rep(i,0,R) {
    rep(j,0,C) {
      graph tmp_G = G;
      if (G.at(i).at(j) == 0) continue;
      dfs(tmp_G, i, j);
      ans = max(ans, max_cnt);
      max_cnt = 0;
    }
  }
    
  cout << ans << endl;
}
