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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i,0,M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
  }

  int ans = -1;
  rep(i,0,N) {
    int cnt = 0;
    bool can = true;
    queue<int> que;
    que.push(i);
    vector<bool> seen(N, false);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      if (seen.at(v)) continue;
      seen.at(v) = true;
      cnt++;
      for (auto nv : G.at(v)) {
        que.push(nv);
      }
    }
    if (cnt == N && can) {
      if (ans != -1) {
        cout << -1 << endl;
        return 0;
      } else {
        ans = i+1;
      }
    }
  }

  if (ans != -1) cout << ans << endl;
  else cout << -1 << endl;
}
