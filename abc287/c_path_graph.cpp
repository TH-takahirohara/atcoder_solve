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
    int u,v;
    cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  int hen1 = 0;
  int hen2 = 0;
  vector<int> hen1v;
  rep(i,0,N) {
    if (G.at(i).size() == 1) {
      hen1++;
      hen1v.push_back(i);
    } else if (G.at(i).size() == 2) {
      hen2++;
    }
  }

  if (hen1 != 2 || hen2 != N-2) {
    cout << "No" << endl;
    return 0;
  }

  vector<bool> seen(N, false);
  queue<int> que;
  que.push(hen1v.at(0));
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    if (seen.at(v)) continue;
    seen.at(v) = true;

    for (auto nv : G.at(v)) {
      if (seen.at(nv)) continue;
      que.push(nv);
    }
  }

  int cntt = 0;
  rep(i,0,N) {
    if (seen.at(i)) cntt++;
  }
  if (cntt == N) cout << "Yes" << endl;
  else cout << "No" << endl;
}
