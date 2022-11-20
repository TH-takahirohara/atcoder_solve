// 2次元累積和（imos法）
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
  vector<vector<int>> vec(1505, vector<int>(1505));
  rep(i,0,N) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vec.at(x1).at(y1)++;
    vec.at(x2).at(y1)--;
    vec.at(x1).at(y2)--;
    vec.at(x2).at(y2)++;
  }

  rep(i,0,1504) {
    rep(j,0,1504) {
      vec.at(i).at(j+1) += vec.at(i).at(j);
    }
  }
  rep(j,0,1504) {
    rep(i,0,1504) {
      vec.at(i+1).at(j) += vec.at(i).at(j);
    }
  }

  int ans = 0;
  rep(i,0,1505) {
    rep(j,0,1505) {
      if (vec.at(i).at(j) > 0) ans++;
    }
  }
  cout << ans << endl;
}
