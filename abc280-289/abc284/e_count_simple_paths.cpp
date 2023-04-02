#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N, M;
vector<bool> seen;
vector<vector<int>> G;
int ans = 0;

void dfs(int v) {
  if (ans >= 1000000) return;

  if (seen.at(v)) return;
  seen.at(v) = true;
  ans++; // 頂点に到達したら+1する

  for (auto nv : G.at(v)) {
    if (seen.at(nv)) continue;
    dfs(nv);
  }

  seen.at(v) = false;
}

int main() {
  cin >> N >> M;
  seen.assign(N, false);
  G.assign(N, {});
  rep(i,0,M) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  dfs(0);

  cout << min(ans, 1000000) << endl;
}
