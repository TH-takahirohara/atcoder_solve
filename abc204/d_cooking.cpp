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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  int sum = 0;
  rep(i,0,N) sum += A.at(i);
  
  vector<vector<bool>> dp(N+1, vector<bool>(sum+1, false));
  dp.at(0).at(0) = true;
  
  rep(i,0,N) {
    rep(j,0,sum+1) {
      if (dp.at(i).at(j)) {
        if (j+A.at(i) <= sum) dp.at(i+1).at(j+A.at(i)) = true;
        dp.at(i+1).at(j) = true;
      }
    }
  }
  
  int ans = 1000000000;
  rep(j,0,sum+1) {
    if (dp.at(N).at(j)) ans = min(ans, max(j, sum-j));
  }
  cout << ans << endl;
}

