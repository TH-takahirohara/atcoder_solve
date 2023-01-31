#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int R,C,K;
  cin >> R >> C >> K;
  vector<string> S(R);
  rep(i,0,R) cin >> S.at(i);
  
  int knum = 0;
  rep(i,0,R) rep(j,0,C) if (S.at(i).at(j) == '#') knum++;
  
  int ans = 0;
  for (int i=0; i < (1<<R); i++) {
    for (int j=0; j < (1<<C); j++) {
      int kuro = 0;
      vector<vector<bool>> seen(R, vector<bool>(C, false));
      rep(r,0,R) {
        if (i & (1<<r)) {
          rep(c,0,C) {
            if (S.at(r).at(c) == '#') {
              kuro++;
              seen.at(r).at(c) = true;
            }
          }
        }
      }
      
      rep(c,0,C) {
        if (j & (1<<c)) {
          rep(r,0,R) {
            if (S.at(r).at(c) == '#' && !seen.at(r).at(c)) {
              kuro++;
              seen.at(r).at(c) = true;
            }
          }
        }
      }
      
      if (knum - kuro == K) {
        ans++;
      }
    }
  }
  
  cout << ans << endl;
}

