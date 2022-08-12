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
  ll x,k,d;
  cin >> x >> k >> d;
  x = abs(x);
  
  if (x / d >= k) {
    cout << x - (d*k) << endl;
  } else {
    ll tori = x - (d*(x/d));
    ll nokori = k - (x/d);
    if (nokori % 2 == 0) cout << tori << endl;
    else cout << abs(tori - d) << endl;
  }
}

