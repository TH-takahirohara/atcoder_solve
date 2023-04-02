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
  rep(i,0,M) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  vector<bool> seen(N);
  int ans = 0;
  rep(i,0,N) {
    if (seen.at(i)) continue;
    ans++;

    queue<int> que;
    que.push(i);
    while (!que.empty()) {
      int v = que.front();
      que.pop();

      if (seen.at(v)) continue;
      seen.at(v) = true;

      for (auto nv : G.at(v)) {
        if (seen.at(nv)) continue;
        que.push(nv);
      }
    }
  }
  cout << ans << endl;
}
