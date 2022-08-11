// 解説にあった方法で解いてみた。
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll L;
  cin >> L;
  L--;
  
  vector<bool> vec(12, true);
  ll ans = 1LL;
  ll div = 1;
  rep(i,0,11) {
    ans = ans * L;
    L--;
    
    ans /= div;
    div++;
  }
  cout << ans << endl;
}
