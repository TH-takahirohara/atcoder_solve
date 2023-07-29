#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)
using mint = modint998244353;

int main() {
  string S;
  cin >> S;
  int N = S.size();

  vector<vector<mint>> dp(N+1000, vector<mint>(N+1000));
  if (S.at(0) == ')') {
    cout << 0 << endl;
    return 0;
  } else {
    dp.at(1).at(0) = 1;
  }

  rep(j,0,N-1) {
    rep(i,0,N) {
      if (S.at(j+1) == '?') {
        if (i-1 >= 0) dp.at(i-1).at(j+1) += dp.at(i).at(j);
        if (i+1 <= N-1) dp.at(i+1).at(j+1) += dp.at(i).at(j);
      } else if (S.at(j+1) == '(') {
        if (i+1 <= N-1) dp.at(i+1).at(j+1) = dp.at(i).at(j);
      } else {
        if (i-1 >= 0) dp.at(i-1).at(j+1) = dp.at(i).at(j);
      }
    }
    // rep(i,0,N) {
    //   if (S.at(j) == '?') {
    //     S.at(i-1).at(j)
    //   }
    // }
  }
  cout << dp.at(0).at(N-1).val() << endl;
}
