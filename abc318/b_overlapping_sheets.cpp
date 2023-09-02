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
  cin >> N;
  vector<vector<int>> S(100, vector<int>(100));

  rep(ite,0,N) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    rep(i,c,d) {
      rep(j,a,b) {
        S.at(i).at(j) += 1;
      }
    }
  }

  int ans = 0;
  rep(i,0,100) {
    rep(j,0,100) {
      if (S.at(i).at(j) > 0) ans++;
    }
  }
  cout << ans << endl;
}
