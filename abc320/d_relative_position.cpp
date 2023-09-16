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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  vector<pair<ll,ll>> ans(N, make_pair(1e18,1e18));
  ans.at(0) = make_pair(0,0);

  map<pair<int,int>,pair<ll,ll>> mp;
  rep(i,0,M) {
    int a,b;
    ll x,y;
    cin >> a >> b >> x >> y;
    a--; b--;
    mp[make_pair(a,b)] = make_pair(x,y);
    mp[make_pair(b,a)] = make_pair(-x,-y);
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  // cout << "test1" << endl;

  vector<bool> seen(N, false);
  queue<int> que;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (seen.at(v)) continue;
    seen.at(v) = true;

    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      auto v_za = ans.at(v);
      ans.at(nv) = make_pair(v_za.first + mp.at(make_pair(v,nv)).first, v_za.second + mp.at(make_pair(v,nv)).second);
      que.push(nv);
    }
  }

  rep(i,0,N) {
    if (ans.at(i).first >= 1e17) {
      cout << "undecidable" << endl;
    } else {
      cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
  }

  // rep(i,0,N) {
  //   if (seen1.at(i)) continue;
    
  //   queue<int> que;
  //   que.push(i);
  //   int cnt = 0;
  //   while (!que.empty()) {
  //     int v = que.front();
  //     que.pop();
  //     if (seen1.at(v)) continue;
  //     seen1.at(v) = true;
  //     cnt++;
  //     for (auto nv : G.at(v)) {
  //       que.push(nv);
  //     }
  //   }
  //   if (cnt < N) {

  //   }
  // }
}
