#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 998244353;

int main() {
  ll N,M;
  cin >> N >> M;

  vector<pair<ll,ll>> warp(3);
  rep(i,0,3) {
    ll x,y;
    cin >> x >> y;
    warp.at(i) = make_pair(x,y);
  }

  set<pair<ll,ll>> st;
  rep(i,0,M) {
    ll x,y; cin >> x >> y;
    st.insert(make_pair(x,y));
  }

  map<pair<ll,ll>, ll> mp;
  mp[{0,0}] = 1;
  rep(i,0,N) {
    map<pair<ll,ll>, ll> nmp;
    for (auto kv : mp) {
      rep(j,0,3) {
        auto keyp = kv.first;
        auto val = kv.second;
        ll nx = keyp.first + warp.at(j).first;
        ll ny = keyp.second + warp.at(j).second;
        if (st.count({nx, ny})) continue;
        nmp[{nx, ny}] += val;
        nmp[{nx, ny}] %= MOD;
      }
    }
    swap(mp, nmp);
  }

  ll ans = 0;
  for (auto kv : mp) {
    ans += kv.second;
    ans %= MOD;
  }
  cout << ans << endl;
}
