// 螺旋本の15.4 木の直径 を参考にした。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;

int main() {
  int N;
  cin >> N;
  
  Graph G(N);
  
  rep(i,0,N-1) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  vector<int> dis(N,0);
  vector<bool> seen(N,false);
  queue<int> que;
  
  que.push(0);
  
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    
    if (seen.at(v)) continue;
    
    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      dis.at(nv) = dis.at(v) + 1;
      que.push(nv);
    }
    
    seen.at(v) = true;
  }
  
  int max_s = -1;
  int max_v = 0;
  rep(i,0,N) {
    if (dis.at(i) > max_v) {
      max_v = dis.at(i);
      max_s = i;
    }
  }
  
  vector<int> dist2(N,0);
  vector<bool> seen2(N,false);
  queue<int> que2;
  
  que2.push(max_s);
  
  while (!que2.empty()) {
    int v = que2.front();
    que2.pop();
    
    if (seen2.at(v)) continue;
    
    for (auto nv : G.at(v)) {
      if (seen2.at(nv)) continue;
      dist2.at(nv) = dist2.at(v) + 1;
      que2.push(nv);
    }
    
    seen2.at(v) = true;
  }
  
  int max_v2 = 0;
  rep(i,0,N) {
    if (dist2.at(i) > max_v2) {
      max_v2 = dist2.at(i);
    }
  }
  
  cout << max_v2 + 1 << endl;
}
