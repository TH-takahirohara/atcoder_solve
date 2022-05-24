// 069 a^b mod m は繰り返し二乗法
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 1000000007LL;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

// 累乗（の剰余）
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  ll N,K;
  cin >> N >> K;
    
  if (N==1) {
    cout << K % MOD << endl;
  } else if (N==2) {
    if (K==1) {
      cout << 0 << endl;
      return 0;
    }
    cout << (K % MOD) * ((K-1) % MOD) % MOD << endl;
  } else {
    if (K<=2) {
      cout << 0 << endl;
      return 0;
    }
    ll ans = 1;
    ans = (K % MOD) * ((K-1) % MOD) % MOD * modpow(K-2, N-2, MOD) % MOD;
    cout << ans << endl;
  }
  return 0;
}

