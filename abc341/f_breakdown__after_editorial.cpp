#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i,0,M) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }
  vector<ll> W(N), A(N);
  vector<pair<ll,int>> WA(N); // Wとidxを持つ
  rep(i,0,N) cin >> W.at(i);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) {
    WA.at(i) = make_pair(W.at(i), i);
  }

  sort(WA.begin(), WA.end());

  vector<ll> dp(N); // 頂点i上の1つのコマが寄与する操作回数の最大値
  rep(i,0,N) {
    ll w = WA.at(i).first;
    int idx = WA.at(i).second;

    vector<int> nexts;
    for (auto nv : G.at(idx)) {
      if (W.at(nv) < w) nexts.push_back(nv);
    }
    int nxts_size = nexts.size();

    vector<vector<ll>> dpn(nxts_size + 1, vector<ll>(w+1, -1));
    dpn.at(0).at(0) = 0;
    rep(j,0,nxts_size) {
      int v = nexts.at(j);
      rep(k,0,w) {
        if (dpn.at(j).at(k) < 0) continue;
        chmax(dpn.at(j + 1).at(k), dpn.at(j).at(k));
        if (k + W.at(v) >= w) continue;
        chmax(dpn.at(j + 1).at(k + W.at(v)), dpn.at(j).at(k) + dp.at(v));
      }
    }
    ll mx  = 0;
    rep(j,0,w) {
      chmax(mx, dpn.at(nxts_size).at(j));
    }

    dp.at(idx) = 1 + mx;
  }

  ll ans = 0;
  rep(i,0,N) {
    ans += A.at(i) * dp.at(i);
  }
  cout << ans << endl;
}
