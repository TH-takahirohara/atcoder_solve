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

  bool aida = false;
  string ans = "";
  rep(i,0,S.size()) {
    if (S.at(i) == '|') {
      if (aida) aida = false;
      else aida = true;
      continue;
    } else if (aida) {
      continue;
    }
    ans += S.at(i);
  }
  cout << ans << endl;
}
