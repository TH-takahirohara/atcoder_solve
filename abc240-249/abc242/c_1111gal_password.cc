#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  
  vector<vector<ll>> dp(N, vector<ll>(9, 0));
  
  dp.at(0).assign(9, 1);
  for (int i=1; i<N; i++) {
    for (int j=0; j<9; j++) {
      if (j == 0) {
        dp.at(i).at(j) = dp.at(i-1).at(j) + dp.at(i-1).at(j+1);
      } else if (j == 8) {
        dp.at(i).at(j) = dp.at(i-1).at(j-1) + dp.at(i-1).at(j);
      } else {
        dp.at(i).at(j) = dp.at(i-1).at(j-1) + dp.at(i-1).at(j) + dp.at(i-1).at(j+1);
      }
      dp.at(i).at(j) %= 998244353;
    }
  }
  
  vector<ll> vec = dp.at(N-1);
  ll sum = 0;
  for (int i=0; i<9; i++) {
    sum += vec.at(i);
    sum %= 998244353;
  }
  
  cout << sum << endl;
}

