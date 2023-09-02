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
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  map<int,vector<int>> mp;
  rep(i,0,N) {
    mp[A.at(i)].push_back(i);
  }
  // cout << mp[1].size() << endl;

  ll ans = 0;
  for (auto p : mp) {
    auto key = p.first;
    auto vec = p.second;
    if (vec.size() < 2) continue;
    ll tmp = 0;
    ll cnt = 0;
    ll zen = 0;
    for (int i=0; i < vec.size(); i++) {
      if (i==0) {
        cnt++;
        continue;
      }
      zen = zen + (vec.at(i) - vec.at(i-1) - 1) * cnt;
      cnt++;
      tmp += zen;
    }
    ans += tmp;
  }
  cout << ans << endl;
}
