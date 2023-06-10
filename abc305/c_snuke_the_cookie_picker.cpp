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

  int rst = 1000, red = -1, cst = 1000, ced = -1;
  rep(i,0,R) {
    rep(j,0,C) {
      if (S.at(i).at(j) == '#') {
        rst = min(rst, i);
        red = max(red, i);
        cst = min(cst, j);
        ced = max(ced, j);
      }
    }
  }

  rep(i,rst,red+1) {
    rep(j,cst,ced+1) {
      if (S.at(i).at(j) == '.') {
        cout << i+1 << " " << j+1 << endl;
        return 0;
      }
    }
  }
}
