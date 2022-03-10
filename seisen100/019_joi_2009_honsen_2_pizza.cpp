#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

// D: 環状線の全長
// N: 店舗の個数
// M: 顧客数

int main() {
  ll D, N, M;
  cin >> D >> N >> M;
  vector<ll> tenpo_d(N);
  vector<ll> kyaku(M);
  
  tenpo_d.at(0) = 0;
  rep(i, 1, N) cin >> tenpo_d.at(i);
  rep(i, 0, M) cin >> kyaku.at(i);
  
  sort(tenpo_d.begin(), tenpo_d.end());
  
  ll ans = 0LL;
  rep(i, 0, M) {
    ll v_cus = kyaku.at(i);
    
    ll right = N-1;
    ll left = 0;
    while (right - left > 1) {
      ll mid = left + (right - left) / 2;
      if (tenpo_d.at(mid) >= v_cus) right = mid;
      else left = mid;
    }
    
    ans += min({abs(tenpo_d.at(right) - v_cus), abs(v_cus - tenpo_d.at(left)), D - v_cus});
  }
  
  cout << ans << endl;
}
