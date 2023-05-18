#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

// using mint = modint998244353;
ll MOD = 998244353;

int main() {
  int N;
  cin >> N;
  vector<vector<ll>> vec(2, vector<ll>(N));
  vector<vector<ll>> dp(2, vector<ll>(N));

  rep(i,0,N) {
    ll a,b;
    cin >> a >> b;
    vec.at(0).at(i) = a;
    vec.at(1).at(i) = b;
  }

  dp.at(0).at(0) = 1;
  dp.at(1).at(0) = 1;
  rep(j,1,N) {
    rep(i,0,2) {
      if (vec.at(i).at(j) != vec.at(i).at(j-1)) {
        dp.at(i).at(j) += dp.at(i).at(j-1);
        dp.at(i).at(j) %= MOD;
      }
      if (vec.at(i).at(j) != vec.at(1-i).at(j-1)) {
        dp.at(i).at(j) += dp.at(1-i).at(j-1);
        dp.at(i).at(j) %= MOD;
      }
    }
  }
  // rep(i,0,2) {
  //   rep(j,0,N) {
  //     cout << dp.at(i).at(j) << " ";
  //   }
  //   cout << endl;
  // }
  ll ans = (dp.at(0).at(N-1) + dp.at(1).at(N-1)) % MOD;
  cout << ans << endl;
}
