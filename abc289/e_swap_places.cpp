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
  int T;
  cin >> T;
  rep(ite,0,T) {
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    rep(i,0,N) cin >> C.at(i);

    int ans = 1e9;
    vector<vector<int>> G(N);
    rep(i,0,M) {
      int u,v;
      cin >> u >> v;
      u--; v--;
      G.at(u).push_back(v);
      G.at(v).push_back(u);
    }

    vector<vector<int>> ex(N, vector<int>(N,1e9));
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    pq.push(make_pair(0, make_pair(0,N-1)));
    while (!pq.empty()) {
      auto v = pq.top();
      pq.pop();
      int n = v.first;
      int ta = v.second.first;
      int ao = v.second.second;

      if (v.first >= ex.at(ta).at(ao)) continue;
      ex.at(ta).at(ao) = v.first;

      for (auto nta : G.at(ta)) {
        for (auto nao : G.at(ao)) {
          if (C.at(nta) != C.at(nao)) {
            pq.push(make_pair(n+1, make_pair(nta,nao)));
          }
        }
      }
    }
    if (ex.at(N-1).at(0) >= 1e9/2) cout << -1 << endl;
    else cout << ex.at(N-1).at(0) << endl;
  }
}
