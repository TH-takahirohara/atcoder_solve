#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int R,C;
  cin >> R >> C;
  vector<string> G(R);
  rep(i,0,R) cin >> G.at(i);

  vector<vector<bool>> seen(R, vector<bool>(C, false));
  // seen.at(0).at(0) = true;

  pair<int,int> cur = make_pair(0,0);
  bool mugen = false;
  
  while (true) {
    int nowr = cur.first;
    int nowc = cur.second;
    seen.at(nowr).at(nowc) = true;
    int nxr, nxc;
    if (G.at(nowr).at(nowc) == 'U') {
      if (nowr == 0) {
        break;
      } else {
        nxr = nowr - 1;
        nxc = nowc;
      }
    } else if (G.at(nowr).at(nowc) == 'D') {
      if (nowr == R-1) break;
      nxr = nowr + 1;
      nxc = nowc;
    } else if (G.at(nowr).at(nowc) == 'L') {
      if (nowc == 0) break;
      nxr = nowr;
      nxc = nowc - 1;
    } else {
      if (nowc == C-1) break;
      nxr = nowr;
      nxc = nowc + 1;
    }
    if (seen.at(nxr).at(nxc)) {
      mugen = true;
      break;
    }
    cur = make_pair(nxr, nxc);
  }

  if (mugen) cout << -1 << endl;
  else cout << cur.first + 1 << " " << cur.second + 1 << endl;
}
