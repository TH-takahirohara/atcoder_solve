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
  string S, T;
  cin >> S >> T;

  string nt = "";
  transform(T.begin(), T.end(), T.begin(), ::tolower);
  
  bool can = false;
  int idx = 0;
  if (T.at(2) != 'x') {
    rep(i,0,S.size()) {
      if (S.at(i) == T.at(idx) && idx < 3) {
        idx++;
        if (idx == 3) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  } else {
    rep(i,0,S.size()) {
      if (S.at(i) == T.at(idx) && idx < 3) {
        idx++;
        if (idx == 2) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
