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
  cin >> N >> M;
  vector<ll> A(N), B(M);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,M) cin >> B.at(i);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  ll ng = 0;
  ll ok = 1e10;
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;
    int urite = upper_bound(A.begin(), A.end(), mid) - A.begin();
    int kaite = B.size() - (lower_bound(B.begin(), B.end(), mid) - B.begin());

    if (urite >= kaite) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
