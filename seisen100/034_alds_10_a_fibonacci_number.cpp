#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  vector<int> dp(N+1, 0);
  dp.at(0) = 1;
  dp.at(1) = 1;
  
  rep(i,2,N+1) {
    dp.at(i) = dp.at(i-1) + dp.at(i-2);
  }
  
  cout << dp.at(N) << endl;
}
