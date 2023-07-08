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
  ll K;
  cin >> N >> K;
  // vector<ll> A(N), B(N);
  // rep(i,0,N) cin >> A.at(i) >> B.at(i);
  vector<pair<ll,ll>> P(N);
  ll sum = 0;
  rep(i,0,N) {
    ll a,b;
    cin >> a >> b;
    sum += b;
    P.at(i) = make_pair(a, b);
  }

  sort(P.begin(), P.end());
  if (sum <= K) {
    cout << 1 << endl;
    return 0;
  }

  rep(i,0,N) {
    auto p = P.at(i);
    ll niti = p.first;
    ll jou = p.second;
    sum -= jou;
    if (sum <= K) {
      cout << niti + 1 << endl;
      return 0;
    }
  }
}
