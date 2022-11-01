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
  ll N;
  cin >> N;

  if (N % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  ll bunbo = 10;
  while (N / bunbo > 0) {
    ans += N / bunbo;
    bunbo *= 5;
  }
  cout << ans << endl;
}
