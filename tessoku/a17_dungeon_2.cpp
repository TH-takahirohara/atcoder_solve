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
  int N;
  cin >> N;
  vector<int> dp(N), A(N), B(N);
  rep(i,0,N-1) cin >> A.at(i+1);
  rep(i,0,N-2) cin >> B.at(i+2);

  rep(i,0,N) {
    if (i+1 < N) {
      if (dp.at(i+1) == 0) dp.at(i+1) = dp.at(i) + A.at(i+1);
      else dp.at(i+1) = min(dp.at(i+1), dp.at(i) + A.at(i+1));
    }
    if (i+2 < N) {
      if (dp.at(i+2) == 0) dp.at(i+2) = dp.at(i) + B.at(i+2);
      else dp.at(i+2) = min(dp.at(i+2), dp.at(i) + B.at(i+2));
    }
  }

  vector<int> ans;
  int idx = N-1;
  while (idx >= 0) {
    ans.push_back(idx);
    if (idx >= 1 && dp.at(idx) == A.at(idx) + dp.at(idx - 1)) idx -= 1;
    else idx -= 2;
  }

  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  rep(i,0,ans.size()) {
    cout << ans.at(i) + 1 << " ";
  }
  cout << endl;
}
