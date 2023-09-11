#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, -1, 0, 1};

bool dame(char c) {
  if (c == '#' || c == '>' || c == 'v' || c == '<' || c == '^') return true;
  else return false;
}

int main() {
  int R, C;
  cin >> R >> C;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);
  vector<string> SN = S;

  pair<int,int> st, ed;
  rep(i,0,R) {
    rep(j,0,C) {
      if (S.at(i).at(j) == '>') {
        int nj = j+1;
        while (true) {
          if (nj >= C) break;
          if (dame(S.at(i).at(nj))) break;
          SN.at(i).at(nj) = '!';
          nj++;
        }
      } else if (S.at(i).at(j) == '<') {
        int nj = j-1;
        while (true) {
          if (nj < 0) break;
          if (dame(S.at(i).at(nj))) break;
          SN.at(i).at(nj) = '!';
          nj--;
        }
      } else if (S.at(i).at(j) == 'v') {
        int ni = i + 1;
        while (true) {
          if (ni >= R) break;
          if (dame(S.at(ni).at(j))) break;
          SN.at(ni).at(j) = '!';
          ni++;
        }
      } else if (S.at(i).at(j) == '^') {
        int ni = i - 1;
        while (true) {
          if (ni < 0) break;
          if (dame(S.at(ni).at(j))) break;
          SN.at(ni).at(j) = '!';
          ni--;
        }
      } else if (S.at(i).at(j) == 'S') {
        st = make_pair(i,j);
      } else if (S.at(i).at(j) == 'G') {
        ed = make_pair(i,j);
      }
    }
  }

  queue<pair<pair<int,int>,int>> que;
  que.push(make_pair(st, 0));
  int ans = -1;
  vector<vector<bool>> seen(R, vector<bool>(C, false));
  while (!que.empty()) {
    auto pp = que.front();
    que.pop();
    auto p = pp.first;
    int kyori = pp.second;

    if (seen.at(p.first).at(p.second)) continue;
    seen.at(p.first).at(p.second) = true;
    
    rep(i,0,4) {
      int nr = p.first + dr.at(i);
      int nc = p.second + dc.at(i);
      if (nr >= R || nr < 0 || nc >= C || nc < 0) continue;
      if (seen.at(nr).at(nc)) continue;
      if (SN.at(nr).at(nc) == '.') {
        que.push(make_pair(make_pair(nr,nc), kyori + 1));
      } else if (SN.at(nr).at(nc) == 'G') {
        cout << kyori + 1 << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
