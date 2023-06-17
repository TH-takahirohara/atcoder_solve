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
  int N;
  cin >> N;
  vector<ll> X(N), Y(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i);
  vector<vector<ll>> dp(2, vector<ll>(N+1));
  dp.at(1).at(0) = -1;

  rep(i,0,N) {
    dp.at(0).at(i+1) = dp.at(0).at(i);
    dp.at(1).at(i+1) = dp.at(1).at(i);
    if (dp.at(0).at(i) >= 0) { // お腹を壊していない場合
      if (X.at(i) == 0) dp.at(0).at(i+1) = max(dp.at(0).at(i+1), dp.at(0).at(i) + Y.at(i));
      else dp.at(1).at(i+1) = max(dp.at(1).at(i+1), dp.at(0).at(i) + Y.at(i));
    }
    if (dp.at(1).at(i) >= 0) {
      if (X.at(i) == 0) dp.at(0).at(i+1) = max(dp.at(0).at(i+1), dp.at(1).at(i) + Y.at(i));
    }
  }
  cout << max(dp.at(0).at(N), dp.at(1).at(N)) << endl;
}
