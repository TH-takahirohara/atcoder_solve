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
  int N, K;
  ll D;
  cin >> N >> K >> D;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(D,-1)));
  dp.at(0).at(0).at(0) = 0;
  rep(i,0,N) {
    rep(j,0,K+1) {
      rep(k,0,D) {
        if (dp.at(i).at(j).at(k) == -1) continue;
        ll n = dp.at(i).at(j).at(k);
        // A[i]を足さない場合
        dp.at(i+1).at(j).at(k) = max(dp.at(i+1).at(j).at(k), n);
        // A[i]を足す場合
        if (j < K) {
          dp.at(i+1).at(j+1).at((n + A.at(i)) % D) = max(dp.at(i+1).at(j+1).at((n + A.at(i)) % D), n + A.at(i));
        }
      }
    }
  }
  cout << dp.at(N).at(K).at(0) << endl;
}
