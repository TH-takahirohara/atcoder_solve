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
  int N, K, P;
  cin >> N >> K >> P;
  vector<ll> C(N);
  vector<vector<int>> A(N, vector<int>(K));
  rep(i,0,N) {
    cin >> C.at(i);
    rep(j,0,K) {
      cin >> A.at(i).at(j);
    }
  }

  map<vector<int>, ll> mp;
  vector<int> zero(K);
  mp[zero] = 0;
  rep(iter,0,N) {
    map<vector<int>, ll> nmp;
    for (auto p : mp) {
      vector<int> key = p.first;
      ll val = p.second;
      vector<int> nk = key;
      rep(i,0,K) {
        nk.at(i) = min(P, nk.at(i) + A.at(iter).at(i));
      }
      if (nmp.count(nk)) {
        nmp.at(nk) = min(nmp.at(nk), val + C.at(iter));
      } else {
        nmp[nk] = val + C.at(iter);
      }
      if (nmp.count(key)) {
        nmp.at(key) = min(nmp.at(key), val);
      } else {
        nmp[key] = val;
      }
    }
    mp = nmp;
  }

  ll ans = 1e18;
  for (auto p : mp) {
    vector<int> key = p.first;
    ll val = p.second;
    bool fl = true;
    rep(i,0,K) {
      if (key.at(i) < P) fl = false;
    }
    if (!fl) continue;
    ans = min(ans, val);
  }
  if (ans >= 1e18) cout << -1 << endl;
  else cout << ans << endl;
}
