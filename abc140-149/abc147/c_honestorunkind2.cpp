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
  int N;
  cin >> N;

  vector<vector<pair<int,int>>> vec(N);

  rep(i,0,N) {
    int a; cin >> a;
    rep(iter,0,a) {
      int x,y; cin >> x >> y;
      x--;
      vec.at(i).push_back(make_pair(x,y));
    }
  }
  
  int ans = 0;
  for (int i=0; i<(1<<N); i++) {
    bool can = true;
    vector<int> shou(N,-1);
    rep(tmp,0,N) {
      if (i & (1<<tmp)) shou.at(tmp) = 1;
      else shou.at(tmp) = 0;
    }
    rep(hito,0,N) {
      if (i & (1<<hito)) {
        for (auto p : vec.at(hito)) {
          if (shou.at(p.first) == 0) {
            if (p.second == 1) can = false;
          } else if (shou.at(p.first) == 1) {
            if (p.second == 0) can = false;
          }
        }
      }
    }
    if (can) {
      ans = max(ans, __builtin_popcount(i));
    }
  }
  cout << ans << endl;
}
