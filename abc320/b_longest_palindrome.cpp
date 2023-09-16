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
  string S;
  cin >> S;

  int ans = 1;
  rep(i,0,S.size()) {
    rep(j,i,S.size()) {
      // cout << i << " " << j << endl;
      string s = "";
      rep(k,i,j+1) {
        s += S.at(k);
      }
      bool can = true;
      rep(k,0,s.size()/2) {
        if (s.at(k) != s.at(s.size()-k-1)) can = false;
      }
      if (can) ans = max(ans, (int)s.size());
    }
  }

  cout << ans << endl;
}
