#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N;
vector<vector<int>> G;
vector<bool> seen;

void dfs(int val) {
  seen.at(val) = true;
  cout << val+1 << " ";

  for (auto nv : G.at(val)) {
    if (seen.at(nv)) continue;
    dfs(nv);
    cout << val+1 << " ";
  }
}

int main() {
  cin >> N;
  G.assign(N, {});
  seen.assign(N, false);
  rep(i,0,N-1) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  rep(i,0,N) {
    sort(G.at(i).begin(), G.at(i).end());
  }

  dfs(0);
}
