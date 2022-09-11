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
  int N,X,Y;
  cin >> N >> X >> Y;
  X--;Y--;
  vector<vector<int>> G(N);
  rep(i,0,N-1) {
    G.at(i).push_back(i+1);
    G.at(i+1).push_back(i);
  }
  G.at(X).push_back(Y);
  G.at(Y).push_back(X);

  vector<int> ans(N);
  rep(i,0,N) {
    vector<bool> seen(N);
    queue<pair<int,int>> que;
    que.push(make_pair(i,0));
    seen.at(i) = true;
    while (!que.empty()) {
      auto p = que.front(); que.pop();
      int v = p.first;
      int kyori = p.second;

      for (auto nv : G.at(v)) {
        if (seen.at(nv)) continue;
        seen.at(nv) = true;
        ans.at(kyori+1)++;
        que.push(make_pair(nv, kyori+1));
      }
    }
  }
  rep(i,1,N) cout << ans.at(i) / 2 << endl;
}
