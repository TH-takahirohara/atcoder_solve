// 確率・期待値の問題
// 解説放送のメモ化再帰という方針を見てから実装してAC
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 998244353LL;

// 累乗を求める関数
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// 逆元を求める関数（フェルマーの小定理）
ll modinv(ll a, ll m) {
  return modpow(a, m-2, m);
}

vector<ll> memo(200005, -1);
ll kaku2, kaku1;

ll rec(ll x) {
  if (x == 0) return memo.at(0);
  if (x == 1) return memo.at(1);
  if (memo.at(x) != -1) return memo.at(x);

  memo.at(x) = (1 + kaku1 * rec(x-1) + kaku2 * rec(x-2)) % MOD;
  return memo.at(x);
}

int main() {
  int N;
  ll P;
  cin >> N >> P;

  kaku2 = P * modinv(100, MOD) % MOD;
  kaku1 = (100 - P) * modinv(100, MOD) % MOD;

  memo.at(0) = 0;
  memo.at(1) = 1;
  cout << rec(N) << endl;
}
