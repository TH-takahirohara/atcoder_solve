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

  int ans = 0;
  int zero_ren = 0;
  rep(i,0,S.size()) {
    if (S.at(i) != '0') {
      ans += ((zero_ren / 2) + (zero_ren % 2));
      zero_ren = 0;
      ans++;
    } else {
      zero_ren++;
    }
  }
  ans += ((zero_ren / 2) + (zero_ren % 2));

  cout << ans << endl;
}
