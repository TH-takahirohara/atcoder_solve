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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  mint ans = mint(0);
  rep(i,1,N+1) {
    vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(i+2, vector<mint>(i, 0)));
    dp.at(0).at(0).at(0) = 1;
    rep(j,0,N) { // j番目の整数を選ぶか
      rep(k,0,i+1) { // 選ぶ個数k
        rep(l,0,i) { // iで割った余り
          if (dp.at(j).at(k).at(l) == 0) continue;
          dp.at(j+1).at(k).at(l) += dp.at(j).at(k).at(l);
          if (k != i) dp.at(j+1).at(k+1).at((l + A.at(j)) % i) += dp.at(j).at(k).at(l);
        }
      }
    }
    ans += dp.at(N).at(i).at(0);
  }
  cout << ans.val() << endl;
}
