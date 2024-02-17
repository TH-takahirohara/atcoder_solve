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
  vector<ll> A(N), S(N), T(N);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N-1) cin >> S.at(i) >> T.at(i);

  rep(i,0,N-1) {
    ll num = A.at(i) / S.at(i);
    A.at(i+1) += T.at(i) * num;
  }
  cout << A.at(N-1) << endl;
}
