// 082 部分問題に分解する／数列の和の公式
// 3つREが出ていて分からなかったので、テストケースを見た。
// stollで範囲外エラーが出ていたので、stoullに直してACした。
#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ull MOD = 1000000007LL;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int calc2(mint left, mint right, int siz) {
  mint tmp = (left + right) * (right - left + 1) / 2 * siz;
  return tmp.val();
}

ull nine(int num) {
  string str = "";
  rep(i,0,num) str += "9";
  return stoull(str);
}

ull ini(int num) {
  string str = "1";
  rep(i,0,num-1) str += "0";
  return stoull(str);
}

int main() {
  ull L,R;
  string Lstr,Rstr;
  cin >> L >> R;
  Lstr = to_string(L);
  Rstr = to_string(R);
  
  int size_L = Lstr.size();
  int size_R = Rstr.size();
  
  mint ans = 0;
  rep(siz, size_L, size_R+1) {
    mint lef = max(L, ini(siz)) % MOD;
    mint rig = min(R, nine(siz)) % MOD;
    ans += calc2(lef, rig, siz);
  }
  
  cout << ans.val() << endl;
}

