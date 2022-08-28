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
  double ans = 3.5;
  rep(ite,1,N) {
    double tmp = 0.0;
    int cnt = 0;
    for (int v=6; (double)v > ans; v--) {
      tmp += (double)v / 6;
      cnt++;
    }
    tmp += ans / ((double)6 / (6 - cnt));
    ans = tmp;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
