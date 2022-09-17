#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)


vector<int> dc = {-1, -1, 0, 0, 1, 1};
vector<int> dr = {-1, 0, -1, 1, 0, 1};
vector<vector<bool>> vec(2005, vector<bool>(2005, false));

void dfs(int r, int c) {
  vec.at(r).at(c) = false;
  rep(i,0,6) {
    int nr = r + dr.at(i);
    int nc = c + dc.at(i);
    if (nr < 0 || nc < 0 || nr > 2002 || nc > 2002) continue;
    if (!vec.at(nr).at(nc)) continue;
    dfs(nr,nc);
  }
}

int main() {
  int N; cin >> N;
  vector<int> X(N), Y(N);
  rep(i,0,N) {
    int x,y;
    cin >> x >> y;
    X.at(i) = x+1001;
    Y.at(i) = y+1001;
  }

  rep(i,0,N) {
    vec.at(Y.at(i)).at(X.at(i)) = true;
  }

  int ans = 0;
  rep(r,0,2003) {
    rep(c,0,2003) {
      if (vec.at(r).at(c)) {
        ans++;
        dfs(r,c);
      }
    }
  }
  cout << ans << endl;
}
