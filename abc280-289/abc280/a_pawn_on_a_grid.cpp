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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,0,H) cin >> S.at(i);

  int ans = 0;
  rep(i,0,H) {
    rep(j,0,W) {
      if (S.at(i).at(j) == '#') ans++;
    }
  }
  cout << ans << endl;
}
