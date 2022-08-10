// 動的計画法(DP)の問題
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll N;
  cin >> N;
  vector<int> vec(N);
  rep(i,0,N) {
    string str;
    cin >> str;
    if (str == "AND") vec.at(i) = 1;
    else vec.at(i) = 0;
  }
  
  // dp.at(0)の行がTrue、dp.at(1)の行がFalseに対応
  vector<vector<ll>> dp(2, vector<ll>(N+1));
  dp.at(0).at(0) = 1; dp.at(1).at(0) = 1;
  
  rep(j,0,N) {
    if (vec.at(j) == 1) {
      dp.at(0).at(j+1) += dp.at(0).at(j);
      dp.at(1).at(j+1) += dp.at(0).at(j) + 2 * dp.at(1).at(j);
    } else {
      dp.at(0).at(j+1) += 2 * dp.at(0).at(j) + dp.at(1).at(j);
      dp.at(1).at(j+1) += dp.at(1).at(j);
    }
  }
  
  cout << dp.at(0).at(N) << endl;
}


