#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  rep(r,0,H) {
    rep(c,0,W) {
      if (r < B) {
        if (c < A) {
          cout << 0;
        } else {
          cout << 1;
        }
      } else {
        if (c < A) {
          cout << 1;
        } else {
          cout << 0;
        }
      }
    }
    cout << endl;
  }
}
