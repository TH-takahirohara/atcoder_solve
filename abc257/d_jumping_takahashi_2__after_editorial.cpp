// ワーシャルフロイド法を使い、多少近いところまでできたが、下記の誤りがあった。修正後にACした。
// 1. ワーシャルフロイドの初期化の誤り　i,jについて、最初(i,j)=(j,i)としていたが、題意から(i,j)!=(j,i)である
// 2. ansの出し方の誤り　ワーシャルフロイドで計算後、全ての座標の最大値を答えにしていたが、最適な始点を決める問題なので、行ごとの最大値を出して、それらの最小値を求める必要があった。
// 3. 答えの出力の誤り　浮動小数点で答えを出力していた。整数に明確に置き換える必要があった。
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

double INF = 1000000000000.0;

int main() {
  int N;
  cin >> N;
  
  vector<ll> X(N), Y(N), P(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i) >> P.at(i);
  
  vector<vector<double>> vec(N, vector<double>(N,INF));
  
  rep(i,0,N) {
    rep(j,0,N) {
      double tmp = (abs(X.at(i) - X.at(j)) + abs(Y.at(i) - Y.at(j))) / (double)P.at(i);
      vec.at(i).at(j) = tmp;
    }
  }
  
  rep(k,0,N) {
    rep(i,0,N) {
      rep(j,0,N) {
        vec.at(i).at(j) = min(vec.at(i).at(j), max(vec.at(i).at(k) , vec.at(k).at(j)));
      }
    }
  }
  
  double ans = INF;
  rep(i,0,N) {
    double tmp = 0.0;
    rep(j,0,N) {
      tmp = max(tmp, vec.at(i).at(j));
    }
    ans = min(ans, tmp);
  }
  
  cout << (ll)ceil(ans) << endl;
}

