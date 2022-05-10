#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;
vector<int> dp;

void dfs(int pos, int pre, Graph &G) {
  dp.at(pos) = 1;
  for (auto nv : G.at(pos)) {
    if (nv != pre) {
      dfs(nv, pos, G);
      dp.at(pos) += dp.at(nv);
    }
  }
}

int main() {
  int N;
  cin>>N;
  
  Graph G(N);
  vector<int> A(N-1), B(N-1);
  rep(i,0,N-1) {
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
    A.at(i) = a;
    B.at(i) = b;
  }
  
  dp.assign(N,0);
  dfs(0, -1, G);
  
  ll ans = 0;
  rep(i,0,N-1) {
    ll tmp = min(dp.at(A.at(i)), dp.at(B.at(i)));
    ans += tmp * (N-tmp);
  }
  cout << ans << endl;
}

