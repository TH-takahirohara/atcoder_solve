#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 998244353LL;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  vector<vector<ll>> dp(N, vector<ll>(10));
  dp.at(0).at(A.at(0)) = 1;
  
  rep(i,0,N-1) {
    rep(j,0,10) {
      dp.at(i+1).at((j + A.at(i+1)) % 10) += dp.at(i).at(j);
      dp.at(i+1).at((j + A.at(i+1)) % 10) %= MOD;
      dp.at(i+1).at((j*A.at(i+1)) % 10) += dp.at(i).at(j);
      dp.at(i+1).at((j*A.at(i+1)) % 10) %= MOD;
    }
  }
  
  rep(i,0,10) {
    cout << dp.at(N-1).at(i) << endl;
  }
}

