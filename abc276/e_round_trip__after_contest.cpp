#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<int> dc = {1, 0, -1, 0};
vector<int> dr = {0, -1, 0, 1};

int main() {
  int R, C;
  cin >> R >> C;
  vector<string> vec(R);
  rep(i,0,R) cin >> vec.at(i);

  int r0 = -1, c0 = -1;
  rep(r,0,R) rep(c,0,C) if (vec.at(r).at(c) == 'S') r0 = r, c0 = c;

  bool can = false;
  rep(iter,0,4) {
    int sr = r0 + dr.at(iter);
    int sc = c0 + dc.at(iter);
    if (sr < 0 || sr >= R || sc < 0 || sc >= C) continue;
    if (vec.at(sr).at(sc) == '#') continue;

    vector<vector<bool>> seen(R, vector<bool>(C, false));
    seen.at(r0).at(c0) = true;
    queue<vector<int>> que;
    que.push({sr,sc,1});

    while (!que.empty()) {
      auto v = que.front(); que.pop();
      int r = v.at(0);
      int c = v.at(1);
      int k = v.at(2);
      if (seen.at(r).at(c)) continue;
      seen.at(r).at(c) = true;

      rep(i,0,4) {
        int nr = r + dr.at(i);
        int nc = c + dc.at(i);
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (vec.at(nr).at(nc) == 'S' && k > 2) {
          can = true;
          break;
        }
        if (vec.at(nr).at(nc) == '#') continue;
        if (seen.at(nr).at(nc)) continue;
        que.push({nr,nc,k+1});
      }
      if (can) break;
    }
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
