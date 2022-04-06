// 1 2
// 2 4
// 2 3
// 2 2
// という入力があった場合、左端がある値の場合の時の右端の値の累積をとる。
// 左端1の路線の累積 [0 1 1 1]
// 左端2の路線の累積 [0 1 2 3]
// 左端3の路線の累積 [0 0 0 0]
// p,q = 1,4 の場合、左端1の路線の累積の4番目の項 + 左端2の路線の累積の4番目の項 + ... とすれば良い。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const int MAX = 1000000;
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
  int N,M,Q;
  cin >> N >> M >> Q;
  
  vector<vector<int>> vec(N, vector<int>(N,0));
  
  rep(i,0,M) {
    int L,R;
    cin >> L >> R;
    L--;R--;
    vec.at(L).at(R) += 1;
  }
  
  rep(i,0,N) {
    rep(j,0,N-1) {
      vec.at(i).at(j+1) += vec.at(i).at(j);
    }
  }
  
  rep(iter,0,Q) {
    int p,q;
    cin >> p >> q;
    p--;q--;
    int ans = 0;
    rep(i,p,N) {
      ans += vec.at(i).at(q);
    }
    
    cout << ans << endl;
  }
}

