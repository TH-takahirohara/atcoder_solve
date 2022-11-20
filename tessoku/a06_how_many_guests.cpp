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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<int> rui(N+1);
  rep(i,0,N) rui.at(i+1) = rui.at(i) + A.at(i);

  rep(i,0,Q) {
    int l, r;
    cin >> l >> r;
    l--;r--;
    cout << rui.at(r+1) - rui.at(l) << endl;
  }
}
