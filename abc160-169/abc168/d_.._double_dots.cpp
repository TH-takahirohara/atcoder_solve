#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;

int main() {
  int N,M;
  cin >> N >> M;
  
  Graph G(N);
  rep(i,0,M) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  vector<int> output(N);
  
  vector<bool> seen(N, false);
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
        
    seen.at(v) = true;
    
    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      output.at(nv) = v;
      seen.at(nv) = true;
      que.push(nv);
    }
  }
  
  cout << "Yes" << endl;
  rep(i,1,N) {
    cout << output.at(i)+1 << endl;
  }
}

