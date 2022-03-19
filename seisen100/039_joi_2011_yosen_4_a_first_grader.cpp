#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N;
  cin >> N;
  
  vector<ll> nums(N-1);
  ll sum_num;
  rep(i,0,N-1) cin >> nums.at(i);
  cin >> sum_num;
    
  vector<vector<ll>> dp(N-1, vector<ll>(21, 0));
  
  dp.at(0).at(nums.at(0)) = 1;
  
  rep(i,1,N-1) {
    rep(j,0,21) {
      if (dp.at(i-1).at(j) != 0) {
        if (j-nums.at(i) >= 0) dp.at(i).at(j-nums.at(i)) += dp.at(i-1).at(j);
        if (j+nums.at(i) <= 20) dp.at(i).at(j+nums.at(i)) += dp.at(i-1).at(j);
      }
    }
  }
  
  cout << dp.at(N-2).at(sum_num) << endl;
}
