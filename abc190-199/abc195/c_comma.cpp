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

  ll ans = 0;
  ll tmp = 1000;
  while (tmp <= N) {
    ans += min(tmp * 10 - 1 - (tmp - 1), (N - (tmp - 1))) * ((to_string(tmp).size() - 1) / 3);
    tmp *= 10;
  }

  cout << ans << endl;
}
