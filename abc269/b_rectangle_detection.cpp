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
  vector<string> S(10);
  rep(i,0,10) cin >> S.at(i);

  int yoko_s = 0, yoko_e = 9, tate_s = 0, tate_e = 9;
  // bool tate = false;
  rep(i,0,10) {
    bool yoko = false;
    rep(j,0,10) {
      
      if (!yoko && S.at(i).at(j) == '#') {
        yoko = true;
        yoko_s = j;
      } else if (yoko && S.at(i).at(j) == '.') {
        yoko_e = j-1;
        break;
      }
    }
    
  }

  bool tate = false;
  rep(i,0,10) {
    if (!tate && S.at(i) != "..........") {
      tate_s = i;
      tate = true;
    } else if (tate && S.at(i) == "..........") {
      tate_e = i-1;
      break;
    }
  }

  cout << tate_s +1 << " " << tate_e + 1 << endl;
  cout << yoko_s +1 << " " << yoko_e + 1 << endl;
}
