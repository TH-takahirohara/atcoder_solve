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
  int N,M;
  cin >> N >> M;
  
  vector<vector<ll>> vec(N, vector<ll>(M));
  rep(i,0,N) rep(j,0,M) cin >> vec.at(i).at(j);
  
  bool can = false;
  for (int i=1; i <= 8-M; i++) {
    if ((vec.at(0).at(0) - i) % 7 == 0) can = true;
  }
  if (!can) {
    cout << "No" << endl;
    return 0;
  }
  
  string ans = "Yes";
  rep(i,0,N) {
    rep(j,0,M) {
      if (i==0 && j==0) continue;
      if (j == 0 && vec.at(i).at(j) - vec.at(i-1).at(j) != 7) ans = "No";
      if (j > 0 && vec.at(i).at(j) - vec.at(i).at(j-1) != 1) ans = "No";
    }
  }
  cout << ans << endl;
}

