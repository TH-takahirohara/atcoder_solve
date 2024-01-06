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
  int N, Q;
  cin >> N >> Q;
  vector<pair<int,int>> pos_1(1e6);
  pos_1.at(0) = make_pair(1,0);

  int x = 1;
  int y = 0;
  int cnt = 0;
  rep(i,0,Q) {
    int c;
    cin >> c;
    if (c == 1) { // 移動
      char C;
      cin >> C;
      if (C=='R') {
        x++;
      } else if (C=='L') {
        x--;
      } else if (C=='U') {
        y++;
      } else {
        y--;
      }
      cnt++;
      pos_1.at(cnt) = make_pair(x,y);
    } else { // 座標を求める
      int p;
      cin >> p;
      if (p-cnt-1 >= 0) {
        cout << p - cnt << " " << 0 << endl;
      } else {
        auto pa = pos_1.at(cnt - p + 1);
        cout << pa.first << " " << pa.second << endl;
      }
    }
  }
}
