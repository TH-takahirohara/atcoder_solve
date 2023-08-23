#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};

int main() {
  int R, C;
  cin >> R >> C;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);

  string ans = "No";
  string sn = "snuke";
  vector<vector<bool>> seen(R, vector<bool>(C, false));
  queue<pair<pair<int,int>,int>> que;
  que.push(make_pair(make_pair(0,0), 0));
  while (!que.empty()) {
    auto p = que.front().first;
    int r = p.first;
    int c = p.second;
    int idx = que.front().second;
    que.pop();
    if (seen.at(r).at(c)) continue;
    if (S.at(r).at(c) != sn.at(idx)) continue;
    if (r == R-1 && c == C-1) {
      ans = "Yes";
      break;
    }
    seen.at(r).at(c) = true;

    rep(i,0,4) {
      int nr = r + dr.at(i);
      int nc = c + dc.at(i);
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      que.push(make_pair(make_pair(nr,nc), (idx+1) % 5));
    }
  }
  cout << ans << endl;
}
