#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> C(N), R(N);
  rep(i,0,N) cin >> C.at(i);
  rep(i,0,N) cin >> R.at(i);

  bool t_in_c = false;
  rep(i,0,N) if (C.at(i) == T) t_in_c = true;

  if (t_in_c) { // 色Tが場に出された場合
    int ans = -1;
    int val = 0;
    rep(i,0,N) {
      if (C.at(i) == T && R.at(i) > val) {
        ans = i + 1;
        val = R.at(i);
      }
    }
    cout << ans << endl;
  } else {
    int col_1 = C.at(0);
    int ans = 1;
    int val = R.at(0);
    rep(i,1,N) {
      if (C.at(i) == col_1 && R.at(i) > val) {
        ans = i + 1;
        val = R.at(i);
      }
    }
    cout << ans << endl;
  }
}
