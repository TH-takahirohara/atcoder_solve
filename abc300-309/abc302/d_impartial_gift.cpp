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
  int N, M;
  ll D;
  cin >> N >> M >> D;
  vector<ll> A(N), B(M);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,M) cin >> B.at(i);

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  ll sum = -1;
  rep(i,0,N) {
    ll a = A.at(i);
    auto ite1 = lower_bound(B.begin(), B.end(), a+D);
    if (ite1 != B.end() && abs(*ite1 - a) <= D) sum = max(sum, a + *ite1);
    if (next(ite1, 1) != B.end() && abs(*next(ite1, 1) - a) <= D) sum = max(sum, a + *next(ite1, 1));
    if (ite1 != B.begin() && abs(*prev(ite1, 1) - a) <= D) sum = max(sum, a + *prev(ite1, 1));
    auto ite2 = lower_bound(B.begin(), B.end(), a-D);
    if (ite2 != B.end() && abs(a - *ite2) <= D) sum = max(sum, a + *ite2);
    if (next(ite2, 1) != B.end() && abs(*next(ite2, 1) - a) <= D) sum = max(sum, a + *next(ite2, 1));
    if (ite2 != B.begin() && abs(*prev(ite2, 1) - a) <= D) sum = max(sum, a + *prev(ite2, 1));
  }

  cout << sum << endl;
}
