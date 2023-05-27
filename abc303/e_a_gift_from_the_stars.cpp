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

  vector<int> ans;
  int cnt = 0;
  rep(i,0,N) {
    if (G.at(i).size() >= 3) {
      ans.push_back(G.at(i).size());
      cnt += (G.at(i).size() + 1);
    }
  }

  rep(i,0,(N - cnt) / 3) {
    ans.push_back(2);
  }

  sort(ans.begin(), ans.end());
  rep(i,0,ans.size()) {
    cout << ans.at(i) << " ";
  }
  cout << endl;
}
