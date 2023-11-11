#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N, M;
ll K;
vector<vector<ll>> vec;
vector<vector<ll>> G;
ll ans = 1e18;

bool is_all_seen(vector<bool> seen) {
  rep(i,0,seen.size()) {
    if (!seen.at(i)) return false;
  }
  return true;
}

void rec(ll sum, int seen) {
  if (seen == (1 << N) - 1) {
    ans = min(ans, sum % K);
    return;
  } else {
    rep(i,0,N) {
      if (!(seen & (1 << i))) continue; // 未到達だったらcontinue
      for (auto nv : G.at(i)) {
        if (!(seen & (1 << nv))) {
          int ns = seen | (1 << nv);
          rec(sum + vec.at(i).at(nv), ns);
        }
      }
    }
  }
}

int main() {
  cin >> N >> M >> K;

  vec.assign(N, vector<ll>(N, -1));
  G.assign(N, {});

  rep(i,0,M) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    vec.at(u).at(v) = w;
    vec.at(v).at(u) = w;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  int seen = 0;
  seen = seen | (1 << (N-1));
  rec(0, seen);

  cout << ans << endl;
}
