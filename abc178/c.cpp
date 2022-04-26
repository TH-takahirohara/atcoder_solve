#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 1000000007;

int main() {
  ll N;
  cin >> N;
  
  ll all = 1;
  rep(i,0,N) {
    all *= 10;
    all %= MOD;
  }
  
  ll not0 = 1;
  rep(i,0,N) {
    not0 *= 9;
    not0 %= MOD;
  }
  not0 *= 2;
  not0 %= MOD;
  
  ll only18 = 1;
  rep(i,0,N) {
    only18 *= 8;
    only18 %= MOD;
  }
  
  ll ans = 0;
  ans = all - not0;
  if (ans < 0) ans += MOD;
  else ans %= MOD;
  
  ans += only18;
  ans %= MOD;
  
  cout << ans << endl;
}

