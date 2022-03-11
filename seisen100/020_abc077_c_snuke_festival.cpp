#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  
  rep(i, 0, N) cin >> A.at(i);
  rep(i, 0, N) cin >> B.at(i);
  rep(i, 0, N) cin >> C.at(i);
  
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  
  // 配列Bのある要素をvとした時、配列Aにおいてvより小さい要素数をn_aとし、配列Cにおいてvより大きい
  // 要素数をn_cとした時、n_a * n_cが要素vに対する種類数になる。そのため、配列Bで全探索し、各要素について
  // n_a * n_cを計算した総和が答えになる。
  ll ans = 0LL;
  rep(i,0,N) {
    ll tar_num = B.at(i);
    ll a_cnt = lower_bound(A.begin(), A.end(), tar_num) - A.begin();
    ll c_cnt = N - (upper_bound(C.begin(), C.end(), tar_num) - C.begin());
    ans += a_cnt * c_cnt;
  }
  
  cout << ans << endl;
}

