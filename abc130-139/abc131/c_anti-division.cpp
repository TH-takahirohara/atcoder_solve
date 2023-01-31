#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll a,b,c,d;

ll num(ll x) {
  return b / x - (a - 1) / x;
}

int main() {
  cin >> a >> b >> c >> d;

  ll g = c / __gcd(c, d) * d;
  ll num_candiv = num(c) + num(d) - num(g);
  cout << b - a + 1 - num_candiv << endl;
}
