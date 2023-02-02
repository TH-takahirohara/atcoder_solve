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
  ll X;
  cin >> X;

  string xstr = to_string(X);
  int size = xstr.size();

  if (size == 1) {
    cout << X << endl;
    return 0;
  }

  int pl = size - 2;

  ll n = X;
  rep(i,0,pl) n /= 10;

  ll ans = 0;
  while (true) {
    bool flag = false;
    ll l1 = n / 10;
    ll l2 = n % 10;
    ll tmp = n;
    ll diff = l2 - l1;
    rep(i,0,pl) {
      ll l3 = l2 + diff;
      if (9 < l3 || l3 < 0) break;
      l2 = l3;
      tmp = tmp * 10 + l3;
    }
    if (tmp >= X) {
      ans = tmp;
      break;
    }
    n++;
    if (n == 100) {
      n = 11;
      pl++;
    }
  }
  cout << ans << endl;
}
