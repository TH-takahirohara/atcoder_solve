#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 10007;

int main() {
  ll N;
  string S;
  cin >> N >> S;
  
  vector<vector<ll>> dp(N, vector<ll>(8, 0));
  vector<ll> sn(N,0);
  
  rep(i,0,N) {
    if (S.at(i) == 'J') sn.at(i) = 2;
    else if (S.at(i) == 'O') sn.at(i) = 1;
    else sn.at(i) = 0;
  }
  
  // 初期化
  rep(j,1,8) {
    if (j & (1<<2) && j & (1<<sn.at(0))) dp.at(0).at(j) = 1;
  }
  
  rep(i,1,N) {
    rep(j,1,8) {
      rep(k,1,8) {
        if (j & (1<<sn.at(i)) && (j & k)) {
          dp.at(i).at(j) += dp.at(i-1).at(k);
          dp.at(i).at(j) %= MOD;
        }
      }
    }
  }
  
  ll sum = 0;
  rep(j,1,8) {
    sum += dp.at(N-1).at(j);
    sum %= MOD;
  }
  
  cout << sum << endl;
}
