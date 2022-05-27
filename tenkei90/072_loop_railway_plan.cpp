// 072 "何通りか"の感覚／バックトラック
// 深さ優先探索に「座標の配列（それまでに到達した座標をtrueとしたもの）」を持たせて強引の解いた。
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int R,C;
vector<int> dc = {1, 0, -1, 0};
vector<int> dr = {0, -1, 0, 1};

int cnt_load(vector<vector<bool>> vec) {
  int res = 0;
  rep(i,0,R) {
    rep(j,0,C) {
      if (vec.at(i).at(j)) res++;
    }
  }
  return res;
}

int main() {
  cin >> R >> C;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);
  
  int ans = -1;
  rep(i,0,R) {
    rep(j,0,C) {
      if (S.at(i).at(j) == '#') continue;
      int tmp = -1;
      
      stack<pair<pair<int,int>, vector<vector<bool>>>> sta;
      vector<vector<bool>> vec(R, vector<bool>(C, false));
      vec.at(i).at(j) = true;
      sta.push(make_pair(make_pair(i,j), vec));
      while (!sta.empty()) {
        int r = sta.top().first.first;
        int c = sta.top().first.second;
        vector<vector<bool>> ve = sta.top().second;
        sta.pop();
        
        ve.at(r).at(c) = true;
        rep(dir,0,4) {
          int nr = r + dr.at(dir);
          int nc = c + dc.at(dir);
          
          if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
          if (S.at(nr).at(nc) == '#') continue;
          if (nr == i && nc == j) {
            int cn = cnt_load(ve);
            if (cn > 3) tmp = max(tmp, cn);
          } else if (!ve.at(nr).at(nc)) {
            ve.at(r).at(c) = true;
            sta.push(make_pair(make_pair(nr,nc), ve));
          }
        }
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}

