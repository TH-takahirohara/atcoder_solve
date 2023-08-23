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
  int N;
  ll D;
  cin >> N >> D;
  vector<ll> X(N), Y(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i);
  vector<vector<int>> G(N);

  rep(i,0,N) {
    rep(j,0,N) {
      if (i == j) continue;
      if ((X.at(i) - X.at(j)) * (X.at(i) - X.at(j)) + (Y.at(i) - Y.at(j)) * (Y.at(i) - Y.at(j)) <= D * D) {
        G.at(i).push_back(j);
      }
    }
  }

  vector<bool> kansen(N);
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (kansen.at(v)) continue;
    kansen.at(v) = true;
    for (auto nv : G.at(v)) {
      que.push(nv);
    }
  }

  rep(i,0,N) {
    if (kansen.at(i)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
