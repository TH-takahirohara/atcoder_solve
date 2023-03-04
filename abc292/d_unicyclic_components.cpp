#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

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

  vector<bool> seen(N, false);
  rep(i,0,N) {
    if (seen.at(i)) continue;
    int chou = 0;
    int hen = 0;
    queue<int> que;
    que.push(i);

    while (!que.empty()) {
      int v = que.front();
      que.pop();
      if (seen.at(v)) continue;
      seen.at(v) = true;
      chou++;

      for (auto nv : G.at(v)) {
        hen++;
        if (seen.at(nv)) continue;
        que.push(nv);
      }
    }

    if (hen % 2 == 0 && (hen / 2) == chou) {
      continue;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
