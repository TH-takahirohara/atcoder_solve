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
  vector<int> Q(N);
  rep(i,0,N) cin >> Q.at(i);
  vector<int> A(N), B(N);
  rep(i,0,N) cin >> A.at(i);
  rep(i,0,N) cin >> B.at(i);

  int num_a = 1e9;
  rep(i,0,N) {
    if (A.at(i) == 0) continue;
    num_a = min(num_a, Q.at(i) / A.at(i));
  }
  // cout << "num_a: " << num_a << endl;

  int ans = 0;
  rep(ite,0,num_a+1) {
    vector<int> Qd = Q;
    rep(j,0,N) {
      Qd.at(j) -= A.at(j) * ite;
    }
    int num_b = 1e9;
    rep(j,0,N) {
      if (B.at(j) == 0) continue;
      num_b = min(num_b, max(0, Qd.at(j) / B.at(j)));
    }
    // cout << " ite, num_b: " << ite << " " << num_b << endl;
    ans = max(ans, ite + num_b);
  }
  cout << ans << endl;
}
