#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<int> mr = { 1, 1, -1, -1 };
vector<int> mc = { 1, -1, 1, -1 };

int main() {
  int N,M;
  cin >> N >> M;

  vector<pair<int,int>> vec;
  for (int i=0; i*i<=M; i++) {
    if (sqrt(M-i*i) > floor(sqrt(M-i*i))) {
      continue;
    } else {
      vec.push_back(make_pair(i, floor(sqrt(M-i*i))));
    }
  }

  vector<pair<int,int>> nvec;
  rep(i,0,vec.size()) {
    if (vec.at(i).first > 400 || vec.at(i).second > 400) continue;
    nvec.push_back(vec.at(i));
  }

  vector<vector<int>> dp(N, vector<int>(N, -1));
  dp.at(0).at(0) = 0;

  queue<pair<int,int>> que;
  que.push(make_pair(0,0));
  while (!que.empty()) {
    auto p = que.front(); que.pop();
    int nowr = p.first;
    int nowc = p.second;
    for (auto idou : nvec) {
      int dr = idou.first;
      int dc = idou.second;
      rep(i,0,4) {
        int ndr = dr * mr.at(i);
        int ndc = dc * mc.at(i);
        int nr = nowr + ndr;
        int nc = nowc + ndc;
        if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
        if (dp.at(nr).at(nc) == -1 || dp.at(nowr).at(nowc) + 1 < dp.at(nr).at(nc)) {
          dp.at(nr).at(nc) = dp.at(nowr).at(nowc) + 1;
          que.push(make_pair(nr,nc));
        }
      }
    }
  }

  rep(i,0,N) {
    rep(j,0,N) {
      cout << dp.at(i).at(j) << " ";
    }
    cout << endl;
  }
}
