// 二項係数の問題。切れ目となりうる箇所を11個選ぶ選び方を求める。
// MODを取る必要はないし、11個選ぶことが確定しているので、
// オーバーフローに気をつけて実装してAC
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll L;
  cin >> L;
  L--;
  
  vector<bool> vec(12, true);
  ll ans = 1LL;
  
  rep(i,0,11) {
    ans = ans * L;
    L--;
    
    rep(j,1,12) {
      if (vec.at(j) && (ans % j == 0)) {
        ans /= j;
        vec.at(j) = false;
      }
    }
  }
  cout << ans << endl;
}

