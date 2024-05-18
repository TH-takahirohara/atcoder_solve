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
  ll H;
  cin >> H;

  ll shoku = 0;
  ll tasu = 1;
  ll cnt = 0;
  while (H >= shoku) {
    shoku += tasu;
    tasu *= 2;
    cnt++;
  }
  cout << cnt << endl;
}
