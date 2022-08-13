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
  ll h1,w1;
  cin >> h1 >> w1;
  vector<vector<ll>> A(h1, vector<ll>(w1));
  rep(i,0,h1) rep(j,0,w1) cin >> A.at(i).at(j);

  ll h2,w2;
  cin >> h2 >> w2;
  vector<vector<ll>> B(h2, vector<ll>(w2));
  rep(i,0,h2) rep(j,0,w2) cin >> B.at(i).at(j);

  if (h1 - h2 < 0 || w1 - w2 < 0) {
    cout << "No" << endl;
    return 0;
  }

  string ans = "No";
  for (int rbit=0; rbit<(1<<h1); rbit++) {
    if (h2 != __builtin_popcount(rbit)) continue;
    for (int cbit=0; cbit<(1<<w1); cbit++) {
      vector<vector<ll>> ng(h2);
      if (w2 != __builtin_popcount(cbit)) continue;
      int row = 0;
      rep(i,0,h1) {
        if (!(rbit & (1<<i))) continue;
        rep(j,0,w1) {
          if (cbit & (1<<j)) {
            ng.at(row).push_back(A.at(i).at(j));
          }
        }
        row++;
      }

      bool can = true;
      rep(i,0,h2) {
        rep(j,0,w2) {
          if (ng.at(i).at(j) != B.at(i).at(j)) can = false;
        }
      }
      if (can) ans = "Yes";
    }
  }
  cout << ans << endl;
}
