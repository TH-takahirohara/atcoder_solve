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
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);

  vector<ll> rui(N);
  rep(i,1,N) {
    if (i % 2 == 0) rui.at(i) = rui.at(i-1) + (A.at(i) - A.at(i-1));
    else rui.at(i) = rui.at(i-1);
  }

  int Q;
  cin >> Q;
  rep(ite,0,Q) {
    ll l, r;
    cin >> l >> r;

    int idx_l = upper_bound(A.begin(), A.end(), l) - A.begin() - 1;
    int idx_r = upper_bound(A.begin(), A.end(), r) - A.begin() - 1;

    // cout << idx_l << " " << idx_r << endl;
    ll lsum = 0, rsum = 0;
    if (idx_l % 2 == 0) lsum = rui.at(idx_l);
    else lsum = rui.at(idx_l) + (l - A.at(idx_l));
    if (idx_r % 2 == 0) rsum = rui.at(idx_r);
    else rsum = rui.at(idx_r) + (r - A.at(idx_r));

    cout << rsum - lsum << endl;
  }
}
