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
  ll X, Y, Z;
  cin >> X >> Y >> Z;
  string S;
  cin >> S;
  // reverse(S.begin(), S.end());

  vector<vector<ll>> dp(2, vector<ll>(S.size() + 1, 8e18));
  dp.at(0).at(0) = 0;
  // dp.at(1).at(0) = 0;
  rep(i,0,S.size()) {
    if (S.at(i) == 'a') {
      dp.at(0).at(i+1) = min(dp.at(0).at(i+1), dp.at(0).at(i) + X);
      dp.at(0).at(i+1) = min(dp.at(0).at(i+1), dp.at(1).at(i) + Z + X);
      dp.at(1).at(i+1) = min(dp.at(1).at(i+1), dp.at(0).at(i) + Z + Y);
      dp.at(1).at(i+1) = min(dp.at(1).at(i+1), dp.at(1).at(i) + Y);
    } else {
      dp.at(0).at(i+1) = min(dp.at(0).at(i+1), dp.at(0).at(i) + Y);
      dp.at(0).at(i+1) = min(dp.at(0).at(i+1), dp.at(1).at(i) + Z + Y);
      dp.at(1).at(i+1) = min(dp.at(1).at(i+1), dp.at(0).at(i) + Z + X);
      dp.at(1).at(i+1) = min(dp.at(1).at(i+1), dp.at(1).at(i) + X);
    }
  }
  // rep(i,0,2) {
  //   rep(j,0,S.size()+1) {
  //     cout << dp.at(i).at(j) << " ";
  //   }
  //   cout << endl;
  // }
  cout << min(dp.at(0).at(S.size()), dp.at(1).at(S.size())) << endl;
}
