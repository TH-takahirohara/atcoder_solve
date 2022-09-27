#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N,M,K;

int f(int x, int y) {
  return M*x - 2*x*y + N*y;
}

int main() {
  cin >> N >> M >> K;

  string ans = "No";
  rep(i,0,N+1) {
    rep(j,0,M+1) {
      if (f(i,j) == K) ans = "Yes";
    }
  }
  cout << ans << endl;
}
