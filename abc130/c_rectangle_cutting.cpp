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
  ll w,h,x,y;
  cin >> w >> h >> x >> y;

  double half = (double)w * h / 2;
  if (w % 2 == 0 && w / 2 == x && h % 2 == 0 && h / 2 == y) {
    cout << fixed << setprecision(10) << half << " " << 1 << endl;
  } else {
    cout << fixed << setprecision(10) << half << " " << 0 << endl;
  }
}
