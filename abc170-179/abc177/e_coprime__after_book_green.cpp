#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef vector<vector<int>> Graph;
double PI = 3.14159265359;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll MOD = 1000000007LL;
vector<long long> fact_inv, inv, Com;

/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(int n, int SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
    Com.resize(SIZE + 5);
    Com[0] = 1;
    for (int i = 1; i < SIZE + 5; i++) {
        Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
    }
}

/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(int k) {
    assert(!(k < 0));
    return Com[k];
}

int main() {
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  vector<int> spf(1000100, -1);
  rep(i,2,1000001) {
    if (spf.at(i) != -1) continue;
    for (int j=1; i*j<1000100; j++) {
      if (spf.at(i*j) != -1) continue;
      spf.at(i*j) = i;
    }
  }
  
  vector<int> daburi(1000100, 0);
  bool is_pairwise = true;
  rep(i,0,N) {
    set<int> se;
    int num = A.at(i);
    while (num != 1) {
      se.insert(spf.at(num));
      num /= spf.at(num);
    }
    
    while (!se.empty()) {
      int n = *begin(se);
      se.erase(n);
      if (daburi.at(n) != 0) is_pairwise = false;
      daburi.at(n)++;
    }
  }
  if (is_pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  
  int tmp = A.at(0);
  rep(i,1,N) {
    tmp = __gcd(tmp, A.at(i));
  }
  if (tmp == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
}

