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
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<int> rui_a(N+1), rui_h(N+1);
  rep(i,0,N) {
    rui_a.at(i+1) = rui_a.at(i) + A.at(i);
    rui_h.at(i+1) = rui_h.at(i) + (1 - A.at(i));
  }

  cin >> Q;
  rep(i,0,Q) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    string ans;
    int n_atari = rui_a.at(r+1) - rui_a.at(l);
    int n_hazure = rui_h.at(r+1) - rui_h.at(l);
    int diff = n_atari - n_hazure;
    if (diff == 0) {
      ans = "draw";
    } else if (diff > 0) {
      ans = "win";
    } else {
      ans = "lose";
    }
    cout << ans << endl;
  }
}
