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
  int N;
  cin >> N;
  int matu_n = N % 10;
  int tmpn = N;
  int sen_n = 0;
  while (tmpn > 0) {
    sen_n = tmpn % 10;
    tmpn /= 10;
  }
  int sz = to_string(N).size();

  int ans = 0;
  rep(i,1,N+1) {
    int sen = i % 10;
    int tmpi = i;
    int matu = 0;
    while (tmpi > 0) {
      matu = tmpi % 10;
      tmpi /= 10;
    }

    int res = 0;
    if (sen == matu) res++;
    int num = 10;
    rep(j,1,6) {
      if (sen == 0) break;
      int tmp = sen * num + matu;
      if (j+1 < sz) {
        res += (num / 10);
      } else if (j+1 > sz) {
        break;
      } else {
        if (sen < sen_n) {
          res += (num / 10);
        } else if (sen > sen_n) {
          break;
        } else {
          int pl = N - sen * num;
          if (matu <= matu_n) res++;
          res += pl / 10;
        }
      }
      num *= 10;
    }
    ans += res;
  }
  cout << ans << endl;
}
