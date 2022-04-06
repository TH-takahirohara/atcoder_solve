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
  int R,C,K;
  cin >> R >> C >> K;
  
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);
  
  vector<vector<int>> J(R, vector<int>(C, 0));
  vector<vector<int>> O(R, vector<int>(C, 0));
  vector<vector<int>> I(R, vector<int>(C, 0));
  
  rep(i,0,R) {
    rep(j,0,C) {
      if (S.at(i).at(j) == 'J') J.at(i).at(j) = 1;
      if (S.at(i).at(j) == 'O') O.at(i).at(j) = 1;
      if (S.at(i).at(j) == 'I') I.at(i).at(j) = 1;
    }
  }
  
  vector<vector<int>> rui_j(R+1, vector<int>(C+1, 0));
  vector<vector<int>> rui_o(R+1, vector<int>(C+1, 0));
  vector<vector<int>> rui_i(R+1, vector<int>(C+1, 0));
  rep(i,0,R) {
    rep(j,0,C) {
      rui_j.at(i+1).at(j+1) = rui_j.at(i).at(j+1) + rui_j.at(i+1).at(j) - rui_j.at(i).at(j) + J.at(i).at(j);
      rui_o.at(i+1).at(j+1) = rui_o.at(i).at(j+1) + rui_o.at(i+1).at(j) - rui_o.at(i).at(j) + O.at(i).at(j);
      rui_i.at(i+1).at(j+1) = rui_i.at(i).at(j+1) + rui_i.at(i+1).at(j) - rui_i.at(i).at(j) + I.at(i).at(j);
    }
  }
  
  rep(i,0,K) {
    int ar,ac,br,bc;
    cin >> ar >> ac >> br >> bc;
    ar--;ac--;
    int cnt_j, cnt_o, cnt_i;
    cnt_j = rui_j.at(br).at(bc) - rui_j.at(br).at(ac) - rui_j.at(ar).at(bc) + rui_j.at(ar).at(ac);
    cnt_o = rui_o.at(br).at(bc) - rui_o.at(br).at(ac) - rui_o.at(ar).at(bc) + rui_o.at(ar).at(ac);
    cnt_i = rui_i.at(br).at(bc) - rui_i.at(br).at(ac) - rui_i.at(ar).at(bc) + rui_i.at(ar).at(ac);
    
    cout << cnt_j << " " << cnt_o << " " << cnt_i << endl;
  }
}

