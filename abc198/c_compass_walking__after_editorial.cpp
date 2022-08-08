// r,x,yの型をintにしていたせいで、x*x+y*yの戻り値がオーバーフローしてWAを大量に出していた。
// llに変更して解消した。
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
  ll r,x,y;
  cin >> r >> x >> y;
  
  if (x==0 && y==0) {
    cout << 0 << endl;
  } else if (x*x + y*y == r*r) {
    cout << 1 << endl;
  } else if (floor(sqrt(x*x + y*y) / (2*r)) == 0) {
    cout << 2 << endl;
  } else {
    cout << (ceil(sqrt(x*x + y*y) / r)) << endl;
  }
}

