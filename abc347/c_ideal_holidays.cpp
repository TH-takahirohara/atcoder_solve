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
  ll A, B;
  cin >> N >> A >> B;
  vector<ll> D(N);
  rep(i,0,N) cin >> D.at(i);

  rep(i,0,N) {
    D.at(i) = D.at(i) % (A+B);
  }

  sort(D.begin(), D.end());

  ll max_sabun = 0;
  rep(i,0,N-1) {
    if (D.at(i) == D.at(i+1)) continue;
    max_sabun = max(max_sabun, D.at(i+1) - D.at(i) - 1);
  }
  max_sabun = max(max_sabun, A + B - (D.at(N-1) - D.at(0)) - 1);

  if (max_sabun >= B) cout << "Yes" << endl;
  else cout << "No" << endl;
}
