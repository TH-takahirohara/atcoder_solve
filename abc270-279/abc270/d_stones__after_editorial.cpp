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
  int N, K;
  cin >> N >> K;
  vector<int> A(K);
  rep(i,0,K) cin >> A.at(i);

  vector<int> dp(N+1);
  dp.at(1) = 1;

  rep(i,2,N+1) {
    rep(j,0,K) {
      if (A.at(j) > i) break;
      dp.at(i) = max(dp.at(i), A.at(j) + (i - A.at(j)) - dp.at(i-A.at(j)));
    }
  }
  cout << dp.at(N) << endl;
}
