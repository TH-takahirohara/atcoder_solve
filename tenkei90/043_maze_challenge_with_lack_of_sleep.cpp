#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 1000000000;

vector<int> dc = {1, 0, -1, 0};
vector<int> dr = {0, -1, 0, 1};

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int R,C,rs,cs,rt,ct;
  cin>>R>>C>>rs>>cs>>rt>>ct;
  rs--;cs--;rt--;ct--;
  
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);
  
  vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(4, INF)));
  rep(i,0,4) dp.at(rs).at(cs).at(i) = 0;
  
  queue<pair<pair<int,int>, int>> que;
  que.push(make_pair(make_pair(rs,cs), -1));
  while (!que.empty()) {
    int r = que.front().first.first;
    int c = que.front().first.second;
    int dir = que.front().second;
    que.pop();
    
    rep(i,0,4) {
      int nr = r + dr.at(i);
      int nc = c + dc.at(i);
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      if (S.at(nr).at(nc) == '#') continue;
      
      int nturn;
      if (dir == -1)  nturn = 0;
      else nturn = dp.at(r).at(c).at(dir);
      
      if (i != dir && dir != -1) nturn += 1;
      
      if (chmin(dp.at(nr).at(nc).at(i), nturn)) {
        que.push(make_pair(make_pair(nr,nc), i));
      }
    }
  }
  
  int ans = INF;
  rep(i,0,4) ans = min(ans, dp.at(rt).at(ct).at(i));
  cout << ans << endl;
}

