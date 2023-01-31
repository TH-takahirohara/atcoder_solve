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
  vector<string> vec(R);
  rep(i,0,R) cin >> vec.at(i);

  vector<vector<int>> shou_yoko(R), shou_tate(C);

  rep(i,0,R) {
    shou_yoko.at(i).push_back(-1);
    rep(j,0,C) {
      if (vec.at(i).at(j) == '#') shou_yoko.at(i).push_back(j);
    }
    shou_yoko.at(i).push_back(C);
  }
  rep(j,0,C) {
    shou_tate.at(j).push_back(-1);
    rep(i,0,R) {
      if (vec.at(i).at(j) == '#') shou_tate.at(j).push_back(i);
    }
    shou_tate.at(j).push_back(R);
  }

  int ans = 0;
  rep(i,0,R) {
    rep(j,0,C) {
      if (vec.at(i).at(j) == '#') continue;
      auto yoko = lower_bound(shou_yoko.at(i).begin(), shou_yoko.at(i).end(), j);
      auto tate = lower_bound(shou_tate.at(j).begin(), shou_tate.at(j).end(), i);
      int tmp = (*yoko - *(--yoko) - 1) + (*tate - *(--tate) - 1) - 1;
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}
