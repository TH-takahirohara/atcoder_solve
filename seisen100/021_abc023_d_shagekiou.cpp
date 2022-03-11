#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll max_h = 1000000000000000LL;

int main() {
  ll N;
  cin >> N;
  vector<ll> H(N), S(N);
  rep(i,0,N) {
    cin >> H.at(i);
    cin >> S.at(i);
  }
  
  ll right = max_h;
  ll left = 0LL;
  
  ll ans = 1000000000000000LL;
  while (right - left > 1) {
    ll mid = left + (right - left ) / 2;
    
    // 残り時間を表す配列
    vector<double> times(N);
    rep(i,0,N) {
      times.at(i) = (mid - H.at(i)) / (double)S.at(i);
    }
    sort(times.begin(), times.end());
    
    ll time = 0;
    bool can = true;
    rep(i,0,N) {
      if (time > times.at(i)) {
        can = false;
        break;
      }
      time++;
    }
    
    if (can) {
      ans = min(ans, mid);
      right = mid;
    } else {
      left = mid;
    }
  }
  
  cout << ans << endl;
}

