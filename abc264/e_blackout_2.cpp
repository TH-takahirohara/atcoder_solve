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
  int N,M,E;
  cin >> N >> M >> E;
  vector<pair<int,int>> den(E);
  rep(i,0,E) {
    int u,v;
    cin >> u >> v;
    u--;v--;
    den.at(i) = make_pair(u,v);
  }

  int Q; cin >> Q;
  vector<int> X(Q);
  rep(i,0,Q) {
    cin >> X.at(i);
    X.at(i)--;
  }
  reverse(X.begin(), X.end());

  vector<int> NX;
  NX = X;
  sort(NX.begin(), NX.end());

  vector<pair<int,int>> nden, aden(Q);

  rep(i,0,Q) {
    aden.at(i) = den.at(X.at(i));
  }

  int idx = 0;
  rep(i,0,E) {
    if (idx < Q && i==NX.at(idx)) {
      idx++;
    } else {
      nden.push_back(den.at(i));
    }
  }
  
  vector<vector<int>> G(N+M);
  rep(i,0,nden.size()) {
    auto p = nden.at(i);
    G.at(p.first).push_back(p.second);
    G.at(p.second).push_back(p.first);
  }

  vector<int> righted(N+M, -1);
  // 発電所は2
  rep(i,0,M) righted.at(i+N) = 2;
  queue<int> que;
  rep(i,0,M) que.push(i+N);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nv : G.at(v)) {
      if (righted.at(nv) == -1) {
        righted.at(nv) = 1;
        que.push(nv);
      }
    }
  }

  vector<int> anses;
  // 終了時点の点灯としている都市数
  int ans = 0;
  rep(i,0,N+M) if (righted.at(i) == 1) ans++;

  anses.push_back(ans);

  rep(i,0,Q-1) {
    auto p = aden.at(i);
    int fir = p.first; int sec = p.second;
    G.at(p.first).push_back(p.second);
    G.at(p.second).push_back(p.first);

    // cout << fir << " " << sec << endl;

    if ((righted.at(fir) == 1 || righted.at(fir) == 2) && (righted.at(sec) == 1 || righted.at(sec) == 2)) {
      anses.push_back(ans);
      continue;
    } else if (righted.at(fir) == -1 && righted.at(sec) == -1) {
      anses.push_back(ans);
      continue;
    }

    // firが無点灯の都市とする
    if (righted.at(sec) == -1) swap(fir, sec);
    // cout << righted.at(fir) << " " << righted.at(sec) << endl;

    queue<int> nq;
    nq.push(fir);
    righted.at(fir) = 1;
    ans++;
    while (!nq.empty()) {
      int v = nq.front(); nq.pop();
      for (auto nv : G.at(v)) {
        if (righted.at(nv) == -1) {
          righted.at(nv) = 1;
          ans++;
          nq.push(nv);
        }
      }
    }
    anses.push_back(ans);
  }

  reverse(anses.begin(), anses.end());
  rep(i,0,anses.size()) cout << anses.at(i) << endl;
}
