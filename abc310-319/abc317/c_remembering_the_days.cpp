#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

struct Edge {
    int to;
    ll cost;
};

ll ans = 0;
int N, M;
vector<vector<Edge>> G;
vector<bool> seen;

void rec(int now, ll sum) {
  if (seen.at(now)) {
    return;
  }
  seen.at(now) = true;
  ans = max(ans, sum);

  for (auto ne : G.at(now)) {
    if (seen.at(ne.to)) continue;
    rec(ne.to, sum + ne.cost);
  }
  seen.at(now) = false;
}

int main() {
  cin >> N >> M;
  G.assign(N, {});
  seen.assign(N, false);
  rep(i,0,M) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    G.at(a).push_back(Edge{b,c});
    G.at(b).push_back(Edge{a,c});
  }

  rep(i,0,N) {
    rec(i, 0);
  }
  cout << ans << endl;
}
