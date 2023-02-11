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
  vector<vector<int>> G(M);
  rep(i,0,M) {
    int c;
    cin >> c;
    rep(j,0,c) {
      int a; cin >> a;
      a--;
      G.at(i).push_back(a);
    }
  }

  int ans = 0;
  for (int i=0; i < (1<<M); i++) {
    vector<bool> exist(N, false);
    for (int j=0; j < M; j++) {
      if (i & (1<<j)) {
        rep(k,0,G.at(j).size()) {
          exist.at(G.at(j).at(k)) = true;
        }
      }
    }
    int tmp = 0;
    rep(i,0,N) {
      if (exist.at(i)) tmp++;
    }
    if (tmp == N) ans++;
  }
  cout << ans << endl;
}
