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
  int N;
  cin >> N;

  double ans = 0.0;
  rep(i,0,N-1) {
    ans += (double)N / (N-i-1);
  }
  cout << fixed << setprecision(10) << ans << endl;
}
