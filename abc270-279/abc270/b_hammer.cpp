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
  int X,Y,Z;
  cin >> X >> Y >> Z;

  if (X > 0 && Y < 0) {
    cout << X << endl;
    return 0;
  } else if (X < 0 && Y > 0) {
    cout << -X << endl;
    return 0;
  } else {
    if (abs(X) < abs(Y)) {
      cout << abs(X) << endl;
      return 0;
    } else {
      if (Y > 0 && Z < Y) {
        if (Z > 0) {
          cout << abs(X) << endl;
          return 0;
        } else {
          cout << 2 * abs(Z) + abs(X) << endl;
          return 0;
        }
      } else if (Y < 0 && Y < Z) {
        if (Z < 0) {
          cout << abs(X) << endl;
          return 0;
        } else {
          cout << 2 * abs(Z) + abs(X) << endl;
          return 0;
        }
      } else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
}
