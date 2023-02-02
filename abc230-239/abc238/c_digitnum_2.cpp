// 逆元を使って解く方法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 998244353LL;

ll modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll calc_sum(ll num) {
  return (num % MOD) * ((num+1) % MOD) % MOD * modinv(2,MOD) % MOD;
}

int main() {
  ll N;
  cin>>N;
  
  string S = to_string(N);
  int siz = S.size()-1;
  
  ll sum = 0;
  rep(i,0,siz) {
    ll kake = 9;
    rep(j,0,i) {
      kake *= 10;
    }
    
    sum += calc_sum(kake);
    sum %= MOD;
  }
  
  ll minus = 1;
  ll tmpN = N;
  while (tmpN > 0) {
    tmpN /= 10;
    if (tmpN == 0) break;
    minus *= 10;
  }
  minus -= 1;
  
  sum += calc_sum(N - minus);
  sum %= MOD;
  cout << sum << endl;
}
