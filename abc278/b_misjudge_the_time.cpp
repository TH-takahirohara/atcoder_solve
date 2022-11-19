#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

bool check(int h, int m) {
  // string hs, ms;
  // hs = to_string(h);
  // ms = to_string(m);
  int a,b,c,d;
  if (h < 10) {
    a = 0;
    b = h;
  } else {
    a = h / 10;
    b = h % 10;
  }

  if (m < 10) {
    c = 0;
    d = m;
  } else {
    c = m / 10;
    d = m % 10;
  }

  int nh, nm;
  nh = a*10 + c;
  nm = b*10 + d;
  // cout << nh << " " << nm << endl;
  if (nh >= 0 && nh <= 23 && nm >= 0 && nm <= 59) return true;
  else return false;
}

int main() {
  int H, M;
  cin >> H >> M;

  while (true) {
    if (check(H,M)) break;
    if (H == 23 && M == 59) {
      H = 0;
      M = 0;
    } else if (M == 59) {
      H++;
      M = 0;
    } else {
      M++;
    }
  }
  cout << H << " " << M << endl;
}
