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
  int N,Q;
  cin >> N >> Q;
  
  vector<vector<int>> G(N);
  rep(i,0,N-1) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  vector<int> C(Q), D(Q);
  rep(i,0,Q) {
    int c,d;
    cin >> c >> d;
    c--;d--;
    C.at(i) = c;
    D.at(i) = d;
  }
  
  vector<int> dist(N);
  vector<bool> seen(N, false);
  seen.at(0) = true;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    
    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      seen.at(nv) = true;
      dist.at(nv) = dist.at(v) + 1;
      que.push(nv);
    }
  }
  
  rep(i,0,Q) {
    int c = C.at(i); int d = D.at(i);
    if ((dist.at(c) - dist.at(d)) % 2 == 0) cout << "Town" << endl;
    else cout << "Road" << endl;
  }
}
