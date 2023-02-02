#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

ll MOD = 998244353;

int main() {
  ll N;
  cin >> N;

  if (N >= 0) {
    cout << N % MOD << endl;
  } else {
    // N = -N;
    // ll kake = N / MOD;
    // ll out = -N + MOD * (kake+1);
    // cout << out << endl;
    if (N % MOD == 0) {
      cout << 0 << endl;
    } else if (N % MOD < 0) {
      cout << (N % MOD) + MOD << endl;
    } else {
      cout << (N % MOD) << endl;
    }
  }
}
