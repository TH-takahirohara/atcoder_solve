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
  int N,M;
  cin >> N >> M;
  vector<vector<int>> vec(M);
  rep(i,0,M) {
    int k;
    cin >> k;
    rep(j,0,k) {
      int x; cin >> x;
      x--;
      vec.at(i).push_back(x);
    }
  }

  vector<vector<bool>> han(N, vector<bool>(N, false));
  rep(i,0,N) han.at(i).at(i) = true;

  rep(i,0,M) {
    rep(j,0,vec.at(i).size()) {
      rep(k,0,vec.at(i).size()) {
        if (j==k) continue;
        int x1 = vec.at(i).at(j);
        int x2 = vec.at(i).at(k);
        han.at(x1).at(x2) = true;
        han.at(x2).at(x1) = true;
      }
    }
  }

  string ans = "Yes";
  rep(i,0,N) {
    rep(j,0,N) {
      if (!han.at(i).at(j)) ans = "No";
    }
  }
  cout << ans << endl;
}
