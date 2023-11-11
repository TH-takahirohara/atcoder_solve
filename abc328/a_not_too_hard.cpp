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
  int N, X;
  cin >> N >> X;
  vector<int> S(N);
  rep(i,0,N) cin >> S.at(i);

  int ans = 0;
  rep(i,0,N) {
    if (S.at(i) <= X) ans += S.at(i);
  }
  cout << ans << endl;
}
