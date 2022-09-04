// 解説後AC。ユーザー解説の方で解いた。
// 各頂点のコストの再計算を、priority_queueをダイクストラ法のように使うことで行う。
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef pair<ll,ll> P;

int main() {
  int N,M;
  cin >> N >> M;

  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<vector<ll>> G(N);
  rep(i,0,M) {
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  // 各頂点の初期コストを計算
  vector<ll> cost(N);
  rep(i,0,N) {
    for (auto v : G.at(i)) {
      cost.at(i) += A.at(v);
    }
  }

  ll ans = 0;
  vector<bool> seen(N);
  priority_queue<P, vector<P>, greater<P>> pq;
  rep(i,0,N) pq.push(make_pair(cost.at(i), i));

  while (!pq.empty()) {
    auto [co,v] = pq.top(); pq.pop();

    if (seen.at(v)) continue;
    seen.at(v) = true;
    ans = max(ans, co);

    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      cost.at(nv) -= A.at(v);
      pq.push(make_pair(cost.at(nv), nv));
    }
  }
  cout << ans << endl;
}
