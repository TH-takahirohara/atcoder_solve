#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N, X, Y;
vector<vector<int>> G;
vector<int> ans;
vector<bool> seen;
bool flag = false;

void dfs(int v) {
  ans.push_back(v);

  if (v == Y) {
    // ans = vec;
    flag = true;
    return;
  }

  for (auto nv : G.at(v)) {
    if (seen.at(nv)) continue;
    seen.at(nv) = true;
    dfs(nv);
    if (flag) return;
    seen.at(nv) = false;
  }
  ans.pop_back();
}

int main() {
  cin >> N >> X >> Y;
  X--; Y--;
  G.resize(N);
  seen.resize(N, false);
  rep(i,0,N-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  seen.at(X) = true;
  dfs(X);
  // cout << ans.size();
  rep(i,0,ans.size()) {
    if (i != ans.size()-1) cout << ans.at(i)+1 << " ";
    else cout << ans.at(i)+1 << endl;
  }
}
