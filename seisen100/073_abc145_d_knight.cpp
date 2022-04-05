#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const int MAX = 3000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();
  
  int X,Y;
  cin >> X >> Y;
  
  int num1x = 0;
  int num2x = 0;
  rep(i,0,X+1) {
    if ((X-i) % 2 != 0) continue;
    
    int tmp_1x, tmp_2x;
    tmp_1x = i; tmp_2x = (X-i) / 2;
    if (tmp_1x * 2 + tmp_2x == Y) {
      num1x = tmp_1x;
      num2x = tmp_2x;
      break;
    }
  }
  
  if (num1x == 0 && num2x == 0) {
    cout << 0 << endl;
    return 0;
  }
  
  cout << COM(num1x+num2x, num1x) << endl;
}

