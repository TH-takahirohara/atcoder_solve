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
  string S;
  cin >> S;
  int N = S.size();
  
  vector<char> vec = {'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};
  
  vector<vector<ll>> dp(N, vector<ll>(8, 0));
  
  if (S.at(0) == vec.at(0)) dp.at(0).at(0) = 1;
  
  rep(i,1,N) {
    rep(j,0,8) {
      if (j==0 && S.at(i) == vec.at(j)) dp.at(i).at(j) += 1;
      else if (S.at(i) == vec.at(j)) dp.at(i).at(j) += dp.at(i-1).at(j-1);
      
      dp.at(i).at(j) += dp.at(i-1).at(j);
      dp.at(i).at(j) %= MOD;
    }    
  }
  
  cout << dp.at(N-1).at(7) << endl;
}

