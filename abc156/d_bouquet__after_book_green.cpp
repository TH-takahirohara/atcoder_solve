// 緑精選50問の方針を少し見てから解いた。
// 累乗計算（modpow）については、 https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an を参考にした。
// 二項係数の導出（O(k)の方法）については、 https://algo-logic.info/combination/ を参考にした。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef vector<vector<int>> Graph;
double PI = 3.14159265359;
ll MOD = 1000000007LL;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<long long> fact_inv, inv, Com;

/*  init_nCk :二項係数のための前処理
    計算量:O(k)
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
    ll N,a,b;
    cin >> N >> a >> b;

    // 花の全ての選び方（2^N - 1（全ての花を選ばないパターンを引く））
    ll alln = modpow(2,N,MOD) - 1;

    init_nCk(N,200000);

    ll ans = 0;
    if (alln - nCk(a) < 0) ans = alln - nCk(a) + MOD;
    else ans = alln - nCk(a);
    if (ans - nCk(b) < 0) ans = ans - nCk(b) + MOD;
    else ans = ans - nCk(b);

    cout << ans << endl;
}
