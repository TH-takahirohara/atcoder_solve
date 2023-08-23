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
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> G(N);
  rep(i,0,M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  vector<pair<int,int>> keibi(K);
  rep(i,0,K) {
    int p, h;
    cin >> p >> h;
    p--;
    keibi.at(i) = make_pair(h, p);
  }
  sort(keibi.begin(), keibi.end());
  reverse(keibi.begin(), keibi.end());

  vector<int> seen(N, -1); 
  rep(i,0,K) {
    int pi = keibi.at(i).second;
    int hi = keibi.at(i).first;
    queue<pair<int,int>> que;
    que.push(make_pair(pi,hi));
    while (!que.empty()) {
      auto pa = que.front();
      que.pop();
      int v = pa.first;
      int h = pa.second;
      if (h <= seen.at(v)) continue;
      seen.at(v) = h;
      for (auto nv : G.at(v)) {
        que.push(make_pair(nv, h-1));
      }
    }
  }

  int num = 0;
  rep(i,0,N) if (seen.at(i) >= 0) num++;
  cout << num << endl;
  rep(i,0,N) {
    if (seen.at(i) >= 0) cout << i+1 << " ";
  }
  cout << endl;
}
