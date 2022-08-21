#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  ll N,P,Q,R;
  cin >> N >> P >> Q >> R;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> rui(N+1);
  rep(i,0,N) rui.at(i+1) = A.at(i) + rui.at(i);

  rep(i,0,N) {
    int idxp = lower_bound(rui.begin(), rui.end(), rui.at(i)+P) - rui.begin();
    if (idxp <= N && rui.at(idxp) - rui.at(i) == P) {
      int idxq = lower_bound(rui.begin(), rui.end(), rui.at(idxp)+Q) - rui.begin();
      if (idxq <= N && rui.at(idxq) - rui.at(idxp) == Q) {
        int idxr = lower_bound(rui.begin(), rui.end(), rui.at(idxq)+R) - rui.begin();
        if (idxr <= N && rui.at(idxr) - rui.at(idxq) == R) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
