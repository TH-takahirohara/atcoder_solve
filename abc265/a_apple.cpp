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
  int x,y,n;
  cin >> x >> y >> n;

  int ans = 0;
  if (x*3 > y) {
    // int ans = 0;
    while (n>=3) {
      ans += y;
      n -= 3;
    }
    while (n>0) {
      ans += x;
      n -= 1;
    }
    cout << ans << endl;
  } else {
    while (n>0) {
      ans += x;
      n -= 1;
    }
    cout << ans << endl;
  }
}
