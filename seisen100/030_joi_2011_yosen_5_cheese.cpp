// 数値型を文字型に変換するところでまごついた。下記のようにする。
// char tmp = '0' + k; 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<int> dr = {1, 0, 0, -1};
vector<int> dc = {0, 1, -1, 0};

int main() {
  int R, C, N;
  cin >> R >> C >> N;
  
  vector<string> G(R);
  rep(i,0,R) cin >> G.at(i);
  
  // 巣の座標と工場の座標を配列に格納
  pair<int,int> nes;
  vector<pair<int,int> > factory(N+1);
  rep(k,1,N+1) {
    rep(i,0,R) {
      rep(j,0,C) {
        char tmp = '0' + k;
        if (G.at(i).at(j) == tmp) factory.at(k) = make_pair(i,j);
        if (G.at(i).at(j) == 'S') nes = make_pair(i,j);
      }
    }
  }
    
  int ans = 0;
  rep(i,0,N) {
    vector<vector<int> > dist(R, vector<int>(C, -1));
    queue<pair<int, int>> que;
    
    pair<int,int> tar_p;
    if (i == 0) tar_p = nes;
    else tar_p = factory.at(i);
    dist.at(tar_p.first).at(tar_p.second) = 0;
    que.push(make_pair(tar_p.first, tar_p.second));
    
    while (!que.empty()) {
      pair<int,int> now_p = que.front();
      que.pop();

      rep(i,0,4) {
        int nr = now_p.first + dr.at(i);
        int nc = now_p.second + dc.at(i);
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (G.at(nr).at(nc) == 'X') continue;
        if (dist.at(nr).at(nc) != -1) continue;
        dist.at(nr).at(nc) = dist.at(now_p.first).at(now_p.second) + 1;
        que.push(make_pair(nr, nc));
      }
    }
    
    pair<int,int> nx_fact = factory.at(i+1);
    ans += dist.at(nx_fact.first).at(nx_fact.second);
  }
  
  cout << ans << endl;
}
