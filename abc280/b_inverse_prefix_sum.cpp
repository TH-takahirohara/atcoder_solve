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
  vector<ll> S(N);
  rep(i,0,N) cin >> S.at(i);

  vector<ll> A(N);
  rep(i,0,N) {
    if (i==0) {
      A.at(i) = S.at(i);
      continue;
    }

    A.at(i) = S.at(i) - S.at(i-1);
  }
  rep(i,0,N) cout << A.at(i) << " ";
  cout << endl;
}
