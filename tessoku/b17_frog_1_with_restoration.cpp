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
  vector<int> h(N), dp(N, 2e9);
  rep(i,0,N) cin >> h.at(i);
  dp.at(0) = 0;

  rep(i,0,N) {
    if (i >= 1) dp.at(i) = min(dp.at(i), dp.at(i-1) + abs(h.at(i) - h.at(i-1)));
    if (i >= 2) dp.at(i) = min(dp.at(i), dp.at(i-2) + abs(h.at(i) - h.at(i-2)));
  }

  int idx = N-1;
  vector<int> ans;
  while (idx >= 0) {
    ans.push_back(idx);
    if (idx >= 1 && dp.at(idx) == dp.at(idx-1) + abs(h.at(idx) - h.at(idx-1))) idx -= 1;
    else idx -= 2;
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  rep(i,0,ans.size()) {
    cout << ans.at(i) + 1 << " ";
  }
  cout << endl;
}
