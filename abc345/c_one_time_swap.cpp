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
  string S;
  cin >> S;

  vector<vector<int>> rui(30, vector<int>(2e6));
  rep(i,0,S.size()) {
    int idx = int(S.at(i) - 'a');
    rui.at(idx).at(i) += 1;
  }

  rep(i,0,30) {
    rep(j,0,1.5e6) {
      rui.at(i).at(j+1) += rui.at(i).at(j);
    }
  }

  // rep(i,0,6) {
  //   cout << rui.at(0).at(i) << " ";
  // }
  // cout << endl;

  ll ans = 0;

  map<int,int> mp;
  rep(i,0,S.size()) {
    int idx = int(S.at(i) - 'a');
    mp[idx]++;
  }
  for (auto p : mp) {
    auto value = p.second;
    if (value > 1) {
      ans++;
      break;
    }
  }

  rep(i,0,S.size()) {
    // cout << "i :" << i << endl;
    int idx = int(S.at(i) - 'a');
    int kosuu = rui.at(idx).at(S.size()) - rui.at(idx).at(i);
    // cout << kosuu << endl;
    int betu = (S.size() - i - 1) - kosuu;
    // cout << betu << endl;
    ans += betu;
  }
  cout << ans << endl;
}
