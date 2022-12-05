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
  vector<ll> A(N), B(N), C(N), D(N);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) cin >> B.at(i);
  rep(i,0,N) cin >> C.at(i);
  rep(i,0,N) cin >> D.at(i);

  vector<ll> sum_ab;
  set<ll> st_cd;
  rep(i,0,N) {
    rep(j,0,N) {
      sum_ab.push_back(A.at(i) + B.at(j));
    }
  }
  rep(i,0,N) {
    rep(j,0,N) {
      st_cd.insert(C.at(i) + D.at(j));
    }
  }

  sort(sum_ab.begin(), sum_ab.end());

  string ans = "No";
  rep(i,0,sum_ab.size()) {
    if (K - sum_ab.at(i) < 0) continue;
    if (st_cd.count(K - sum_ab.at(i))) ans = "Yes";
  }
  cout << ans << endl;
}
