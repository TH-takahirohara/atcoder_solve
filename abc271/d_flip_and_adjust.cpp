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
  int N, S;
  cin >> N >> S;
  vector<int> a(N), b(N);
  rep(i,0,N) cin >> a.at(i) >> b.at(i);

  vector<vector<int>> dp(10001, vector<int>(N));
  dp.at(a.at(0)).at(0) = 1;
  dp.at(b.at(0)).at(0) = 2;

  rep(j,0,N-1) {
    rep(i,1,10001) {
      if (dp.at(i).at(j) == 0) continue;
      if (i + a.at(j+1) <= 10000) dp.at(i + a.at(j+1)).at(j+1) = 1;
      if (i + b.at(j+1) <= 10000) dp.at(i + b.at(j+1)).at(j+1) = 2;
    }
  }

  if (dp.at(S).at(N-1) == 0) {
    cout << "No" << endl;
    return 0;
  }

  string ans = "";
  int idx = S;
  for (int j=N-1; j>=0; j--) {
    if (dp.at(idx).at(j) == 1) {
      ans += 'H';
      idx -= a.at(j);
    } else {
      ans += 'T';
      idx -= b.at(j);
    }
  }

  reverse(ans.begin(), ans.end());
  cout << "Yes" << endl;
  cout << ans << endl;
}
