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
  ll X;
  cin >> X;

  if (X == 0) {
    cout << 0 << endl;
    return 0;
  }

  bool plus = true;
  if (X < 0) {
    plus = false;
    X = -X;
  }

  ll shou = X / 10;
  ll amari = X % 10;

  if (plus) {
    if (amari == 0) {
      cout << shou << endl;
    } else {
      cout << shou + 1 << endl;
    }
  } else {
    if (amari == 0) {
      cout << shou * (-1) << endl;
    } else {
      cout << shou * (-1) << endl;
    }
  }
}
