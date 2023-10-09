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
  int N, X;
  cin >> N >> X;
  vector<int> T(N);
  rep(i,0,N) cin >> T.at(i);

  vector<mint> dp(X+1, mint(0));
  dp.at(0) = mint(1);

  mint p = mint(1)/N;
  rep(i,0,X+1) {
    rep(j,0,N) {
      if (i+T.at(j) <= X) dp.at(i+T.at(j)) += dp.at(i) * p;
    }
  }

  mint ans = mint(0);
  rep(i,0,X+1) {
    if (i+T.at(0) > X) ans += dp.at(i) * p;
  }

  cout << ans.val() << endl;
}
