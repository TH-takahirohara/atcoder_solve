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
  int N1, N2, M;
  cin >> N1 >> N2 >> M;
  vector<vector<int>> G(N1+N2);
  rep(i,0,M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  vector<int> kyori(N1+N2);
  vector<bool> seen(N1+N2);
  queue<pair<int,int>> que, que2;
  que.push(make_pair(0,0));
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    int v = p.first;
    int d = p.second;
    if (seen.at(v)) continue;
    seen.at(v) = true;
    kyori.at(v) = d;
    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      que.push(make_pair(nv, d+1));
    }
  }

  que2.push(make_pair(N1+N2-1,0));
  while (!que2.empty()) {
    auto p = que2.front();
    que2.pop();
    int v = p.first;
    int d = p.second;
    if (seen.at(v)) continue;
    seen.at(v) = true;
    kyori.at(v) = d;
    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      que2.push(make_pair(nv, d+1));
    }
  }

  int d1 = 0, d2 = 0;
  rep(i,0,N1) {
    d1 = max(d1, kyori.at(i));
  }
  rep(i,N1,N1+N2) {
    d2 = max(d2, kyori.at(i));
  }
  cout << d1 + d2 + 1 << endl;
}
