// 2次元累積和
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
  vector<vector<int>> X(1505, vector<int>(1505)), rui(1505, vector<int>(1505));
  rep(i,0,N) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    X.at(x).at(y)++;
  }

  rep(i,0,1504) {
    rep(j,0,1504) {
      rui.at(i+1).at(j+1) = rui.at(i).at(j+1) + rui.at(i+1).at(j) - rui.at(i).at(j) + X.at(i).at(j);
    }
  }

  int Q;
  cin >> Q;
  rep(i,0,Q) {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    cout << rui.at(x2+1).at(y2+1) - rui.at(x1).at(y2+1) - rui.at(x2+1).at(y1) + rui.at(x1).at(y1) << endl;
  }
}
