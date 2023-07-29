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
  int R, C;
  cin >> R >> C;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);
  
  rep(i,0,R-8) {
    rep(j,0,C-8) {
      // cout << i+1 << " " << j+1 << endl;
      bool ok = true;
      rep(k,0,3) {
        if (!(S.at(i+k).at(j+0) == '#' && S.at(i+k).at(j+1) == '#' && S.at(i+k).at(j+2) == '#' && S.at(i+k).at(j+3) == '.')) {
          ok = false;
        }
      }
      rep(j2,0,4) {
        if (S.at(i+3).at(j+j2) != '.') {
          ok = false;
        }
      }
      rep(j2,5,9) {
        if (S.at(i+5).at(j+j2) != '.') {
          ok = false;
        }
      }
      rep(k,6,9) {
        if (!(S.at(i+k).at(j+5) == '.' && S.at(i+k).at(j+6) == '#' && S.at(i+k).at(j+7) == '#' && S.at(i+k).at(j+8) == '#')) {
          ok = false;
        }
      }
      if (ok) {
        cout << i+1 << " " << j+1 << endl;
      }
    }
  }
}
