#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int INF = 1000010000;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i,0,N) cin >> vec.at(i);
  
  vector<int> dp(N,INF);
  
  rep(i,0,N) {
    *lower_bound(dp.begin(), dp.end(), vec.at(i)) = vec.at(i);
  }
  
  int ans = 0;
  rep(i,0,N) {
    if (dp.at(i) == INF) {
      ans = i;
      break;
    }
    if (i==N-1) {
      ans = N;
    }
  }
  
  cout << N - ans << endl;
}
