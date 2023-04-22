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

  int K;
  cin >> K;
  vector<vector<int>> kuro(K);
  set<int> siro;
  rep(i,0,K) {
    int p, d;
    cin >> p >> d;
    p--;

    vector<bool> seen(N);
    queue<pair<int,int>> que; // 頂点と距離のペアのqueue
    que.push(make_pair(p,0));
    while (!que.empty()) {
      auto p = que.front();
      que.pop();
      int v = p.first;
      int nd = p.second;

      if (seen.at(v)) continue;
      seen.at(v) = true;

      if (nd < d) {
        siro.insert(v);
        for (auto nv : G.at(v)) {
          if (seen.at(nv)) continue;
          que.push(make_pair(nv,nd+1));
        }
      } else if (nd == d) {
        kuro.at(i).push_back(v);
      }
    }
  }

  vector<bool> is_kuro(N);
  rep(i,0,K) {
    vector<int> vec = kuro.at(i);
    // 黒になるべき頂点がないケース（距離が大きすぎる場合）はNo
    if (vec.size() == 0) {
      cout << "No" << endl;
      return 0;
    }

    bool can = false;
    for (auto v : vec) {
      if (siro.count(v)) continue;
      can = true;
      is_kuro.at(v) = true;
    }
    // 黒にできる頂点がない場合（全て白でなければならないケース）はNo
    if (!can) {
      cout << "No" << endl;
      return 0;
    }
  }

  // 黒にできる頂点は全て黒にする（白の頂点のみになって条件外となるケースを避けるため）
  rep(i,0,N) {
    if (!siro.count(i)) is_kuro.at(i) = true;
  }

  cout << "Yes" << endl;
  rep(i,0,N) {
    if (is_kuro.at(i)) cout << "1";
    else cout << "0";
  }
  cout << endl;
}
