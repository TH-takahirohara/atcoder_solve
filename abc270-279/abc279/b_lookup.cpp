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
  if (T.size() > S.size()) {
    cout << "No" << endl;
    return 0;
  }

  bool ans = false;
  rep(i,0,S.size()-T.size()+1) {
    bool tmp = true;
    rep(j,0,T.size()) {
      if (S.at(i+j) != T.at(j)) tmp = false;
    }
    if (tmp) ans = true;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
