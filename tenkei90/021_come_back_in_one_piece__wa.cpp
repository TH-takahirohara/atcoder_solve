// 半分くらいWAとなる。諦めた。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;
priority_queue<pair<int,int>> que;
Graph G1;
Graph G2;
vector<bool> seen;
int iter = 0;

void dfs(int v, Graph &G) {
  if (seen.at(v)) return;
  
  seen.at(v) = true;
  
  for (auto nv : G.at(v)) {
    if (seen.at(nv)) continue;
    dfs(nv, G);
  }
  
  iter++;
  que.push(make_pair(iter, v));
  return;
}

int main() {
  int N,M;
  cin >> N >> M;
  
  G1.assign(N, {});
  G2.assign(N, {});
  
  rep(i,0,M) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G1.at(a).push_back(b);
    G2.at(b).push_back(a);
  }
  
  seen.assign(N,false);
  rep(i,0,N) {
    if (seen.at(i)) continue;
    dfs(i,G1);
  }
  
  seen.assign(N,false);
  stack<int> sta;
  vector<int> vec;
  while (!que.empty()) {
    int v = que.top().second;
    int num = que.top().first;
    que.pop();
    
    if (seen.at(v)) continue;
    
    int ite = 0;
    sta.push(v);
    while (!sta.empty()) {
      int va = sta.top();
      sta.pop();
      
      seen.at(va) = true;
      
      ite++;
      for (auto nv : G2.at(va)) {
        if (seen.at(nv)) continue;
        sta.push(nv);
      }
    }
    
    vec.push_back(ite);
  }
  
  ll ans = 0LL;
  rep(i,0,vec.size()) {
    int val = vec.at(i);
    if (val > 1) ans += val*(val-1)/2;
  }
  
  cout << ans << endl;
}
