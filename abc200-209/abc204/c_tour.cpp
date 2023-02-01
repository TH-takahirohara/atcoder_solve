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
  int N,M;
  cin >> N >> M;
  
  vector<vector<int>> G(N);
  rep(i,0,M) {
    int a,b; cin >> a >> b;
    a--;b--;
    G.at(a).push_back(b);
  }
  
  int ans = 0;
  rep(sta,0,N) {
    vector<bool> seen(N,false);
    queue<int> que;
    que.push(sta);
    seen.at(sta) = true;
    
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (auto nv : G.at(v)) {
        if (seen.at(nv)) continue;
        seen.at(nv) = true;
        que.push(nv);
      }
    }
    int tmp = 0;
    rep(i,0,N) if (seen.at(i)) tmp++;
    ans += tmp;
  }
  cout << ans << endl;
}

