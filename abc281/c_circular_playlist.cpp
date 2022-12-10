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
  ll T;
  cin >> N >> T;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  ll sum = 0;
  rep(i,0,N) {
    sum += A.at(i);
  }

  T %= sum;

  // vector<ll> rui(N+1);
  // rep(i,0,N) rui.at(i+1) = rui.at(i) + A.at(i);

  // int idx = lower_bound(rui.begin(), rui.end(), T) - rui.begin();
  int idx = 0;
  while (T > 0) {
    if (T < A.at(idx)) break;
    T -= A.at(idx);
    idx = (idx + 1) % N;
  }
  cout << idx + 1 << " " << T << endl;
}
