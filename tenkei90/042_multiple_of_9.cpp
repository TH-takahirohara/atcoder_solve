#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 1000000007LL;

int main() {
  ll K;
  cin>>K;
  
  if (K % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }
  
  vector<ll> dp(K+1, 0);
  dp.at(0) = 1;
  rep(i,1,K+1) {
    rep(j,1,10) {
      if (i-j >= 0) {
        dp.at(i) += dp.at(i-j);
        dp.at(i) %= MOD;
      }
    }
  }
  cout << dp.at(K) << endl;
}

