#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, K;
  cin >> N >> K;
  double ans = 0.0;
  rep(i,1,N+1) {
    double tmp = (double)1 / N;
    if (i >= K) {
      ans += tmp;
      continue;
    }
    int bunbo = 1;
    int num = i;
    while (num < K) {
      bunbo *= 2;
      num *= 2;
    }
    ans += tmp / bunbo;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
