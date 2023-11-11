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
  string S;
  cin >> S;

  vector<int> tonari(N);
  rep(i,1,N) {
    if (S.at(i-1) == S.at(i)) tonari.at(i) = 1;
  }

  vector<int> rui(N+1);
  rep(i,0,N) rui.at(i+1) = rui.at(i) + tonari.at(i);
  // rep(i,0,N+1) cout << rui.at(i) << " ";
  // cout << endl;

  rep(i,0,Q) {
    int l, r;
    cin >> l >> r;
    // l--; r--;
    cout << rui.at(r) - rui.at(l) << endl;
  }
}
