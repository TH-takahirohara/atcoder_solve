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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i,1,N) {
    int p;
    cin >> p;
    p--;
    G.at(p).push_back(i);
  }
  vector<ll> cnt(N, -1000000000);
  rep(i,0,M) {
    int x;
    ll y;
    cin >> x >> y;
    x--;
    cnt.at(x) = max(cnt.at(x), y);
  }

  vector<bool> is_hoken(N);
  queue<pair<int,ll>> que;
  que.push(make_pair(0,-1));
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    int v = p.first;
    ll zan = p.second;
    zan = max(zan, cnt.at(v));
    if (zan >= 0) is_hoken.at(v) = true;
    for (auto nv : G.at(v)) {
      que.push(make_pair(nv, zan - 1));
    }
  }

  int ans = 0;
  rep(i,0,N) {
    if (is_hoken.at(i)) ans++;
  }
  cout << ans << endl;
}
