#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H), T(H);
  rep(i,0,H) cin >> S.at(i);
  rep(i,0,H) cin >> T.at(i);

  vector<vector<int>> vs(W, vector<int>(H)), vt(W, vector<int>(H));
  rep(j,0,W) {
    vector<int> tmpv(H);
    rep(i,0,H) {
      if (S.at(i).at(j) == '#') tmpv.at(i) = 1;
      else tmpv.at(i) = 0;
    }
    vs.at(j) = tmpv;
  }
  rep(j,0,W) {
    vector<int> tmpv(H);
    rep(i,0,H) {
      if (T.at(i).at(j) == '#') tmpv.at(i) = 1;
      else tmpv.at(i) = 0;
    }
    vt.at(j) = tmpv;
  }

  sort(vs.begin(), vs.end());
  sort(vt.begin(), vt.end());

  bool ans = true;
  rep(i,0,W) {
    rep(j,0,H) {
      if (vs.at(i).at(j) != vt.at(i).at(j)) ans = false;
    }
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
