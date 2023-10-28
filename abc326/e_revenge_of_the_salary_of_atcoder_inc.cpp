#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)
using mint = modint998244353;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  mint p = mint(1)/N;
  vector<mint> kakus(N, mint(0));

  mint sum_k = mint(0);
  rep(i,0,N) {
    kakus.at(i) = p + sum_k * p;
    sum_k += kakus.at(i);
  }

  mint ans = mint(0);
  rep(i,0,N) {
    ans += kakus.at(i) * A.at(i);
  }
  cout << ans.val() << endl;
}
