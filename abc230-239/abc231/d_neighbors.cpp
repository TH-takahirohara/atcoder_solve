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
  int N, M;
  cin >> N >> M;
  
  if (M >= N) {
    cout << "No" << endl;
    return 0;
  }
  
  vector<vector<int>> vec(N);
  
  rep(i,0,M) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    vec.at(a).push_back(b);
    vec.at(b).push_back(a);
  }
  
  bool can1 = true;
  rep(i,0,N) {
    if (vec.at(i).size() > 2) can1 = false;
  }
  if (!can1) {
    cout << "No" << endl;
    return 0;
  }
  
  string ans = "Yes";
  vector<bool> seen(N, false);
  rep(i,0,N) {
    if (seen.at(i)) continue;
    
    queue<pair<int,int>> que;
    que.push(make_pair(i,-1));
    while (!que.empty()) {
      auto p = que.front();
      que.pop();
      
      int now = p.first;
      int bef = p.second;
      seen.at(now) = true;
      for (auto nv : vec.at(now)) {
        if (nv == bef) continue;
        if (seen.at(nv)) ans = "No";
        else que.push(make_pair(nv, now));
      }
    }
  }
  cout << ans << endl;
}

