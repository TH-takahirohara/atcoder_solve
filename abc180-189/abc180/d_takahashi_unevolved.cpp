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
  ll x,y,a,b;
  cin >> x >> y >> a >> b;
  
  ll tar = b / (a-1);
  
  ll ans = 0LL;
  if (y < tar) {
    while (x < y) {
      x *= a;
      if (x >= y) break;
      ans++;
    }
    cout << ans << endl;
  } else {
    while (x < tar) {
      x *= a;
      ans++;
    }
    
    ans += (y - x - 1) / b;
    cout << ans << endl;
  }
}

