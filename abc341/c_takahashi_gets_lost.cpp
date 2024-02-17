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
  int R, C, N;
  cin >> R >> C >> N;
  string T;
  cin >> T;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);

  // cout << "test1" << endl;

  int ans = 0;
  rep(r,0,R) {
    rep(c,0,C) {
      if (S.at(r).at(c) == '#') continue;
      // cout << "r,c: " << r << " " << c << endl;
      int nr = r;
      int nc = c;
      bool can = true;
      rep(ite,0,N) {
        char ch = T.at(ite);
        if (ch == 'L') nc--;
        else if (ch == 'R') nc++;
        else if (ch == 'U') nr--;
        else nr++;
        // cout << "nr,nc: " <<  nr << " " << nc << endl;
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
          can = false;
          break;
        }
        if (S.at(nr).at(nc) == '#') {
          can = false;
          break;
        }
      }
      if (can) ans++;
    }
  }

  cout << ans << endl;
}
