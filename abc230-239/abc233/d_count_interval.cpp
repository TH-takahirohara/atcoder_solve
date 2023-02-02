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
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> rui(N+1);
  rep(i,0,N) rui.at(i+1) = rui.at(i) + A.at(i);

  map<ll,vector<int>> mp;
  rep(i,0,N+1) {
    mp[rui.at(i)].push_back(i);
  }

  ll ans = 0;
  rep(i,0,N+1) {
    ll tar = rui.at(i) + K;
    if (!mp.count(tar)) continue;
    ll tmp = mp.at(tar).size() - (upper_bound(mp.at(tar).begin(), mp.at(tar).end(), i) - mp.at(tar).begin());
    ans += tmp;
  }
  cout << ans << endl;
}
