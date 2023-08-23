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
  int N, Q;
  cin >> N >> Q;
  vector<set<int>> G(N);
  int ans = N;
  rep(ite,0,Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      if (G.at(u).size() == 0) ans--;
      if (G.at(v).size() == 0) ans--;
      G.at(u).insert(v);
      G.at(v).insert(u);
      cout << ans << endl;
    } else { // t: 2
      int v;
      cin >> v;
      v--;
      if (G.at(v).size() == 0) {
        cout << ans << endl;
      } else {
        while (!G.at(v).empty()) {
          int nv = *begin(G.at(v));
          G.at(v).erase(nv);
          G.at(nv).erase(v);
          if (G.at(nv).size() == 0) ans++;
        }
        ans++;
        cout << ans << endl;
      }
    }
  }
}
