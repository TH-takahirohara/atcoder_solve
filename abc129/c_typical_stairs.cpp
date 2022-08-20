#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 1000000007LL;

int main() {
  ll N,M;
  cin >> N >> M;
  vector<bool> dang(N+1, false);
  // vector<ll> dang(M);
  rep(i,0,M) {
    ll tmp;
    cin >> tmp;
    dang.at(tmp) = true;
  }

  vector<ll> dp(N+1, 0);
  dp.at(0) = 1;
  rep(i,0,N) {
    if (dp.at(i) == 0 || dang.at(i)) continue;
    dp.at(i+1) += dp.at(i);
    dp.at(i+1) %= MOD;
    if (i+2 <= N) {
      dp.at(i+2) += dp.at(i);
      dp.at(i+2) %= MOD;
    }
  }

  cout << dp.at(N) << endl;
}
