#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  rep(i,0,N-1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  vector<int> nums;
  rep(ite,0,G.at(0).size()) {
    int sta = G.at(0).at(ite);
    queue<int> que;
    que.push(sta);
    vector<bool> seen(N);
    seen.at(0) = true; // 0(1)には行かないようにする
    int cnt = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();

      if (seen.at(v)) continue;
      seen.at(v) = true;
      cnt++;

      for (int nv : G.at(v)) {
        if (seen.at(nv)) continue;
        que.push(nv);
      }
    }

    nums.push_back(cnt);
  }

  sort(nums.begin(), nums.end());
  int ans = 0;
  rep(i,0,nums.size()-1) ans += nums.at(i);
  cout << ans + 1 << endl;
}
