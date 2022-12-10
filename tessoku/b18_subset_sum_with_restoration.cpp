#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<vector<bool>> dp(N+1, vector<bool>(1000000, false));
  dp.at(0).at(0) = true;
  rep(i,0,N) {
    rep(j,0,10005) {
      if (dp.at(i).at(j)) {
        dp.at(i+1).at(j) = true;
        dp.at(i+1).at(j + A.at(i)) = true;
      }
    }
  }

  if (!dp.at(N).at(S)) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> ans;
  for (int i=N-1; i>=0; i--) {
    if (S - A.at(i) >= 0 && dp.at(i).at(S - A.at(i))) {
      ans.push_back(i+1);
      S -= A.at(i);
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  rep(i,0,ans.size()) cout << ans.at(i) << " ";
  cout << endl;
}
