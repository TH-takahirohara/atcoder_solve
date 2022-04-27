// 最終的なNの値が1ではない場合、それは素数なので、
// その値の分をansに加算してあげる必要があることに要注意
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  ll N;
  cin >> N;
  
  ll inin = N;
  
  if (N==1) {
    cout << 0 << endl;
    return 0;
  }
  
  ll ans = 0;
  for (ll i=2; i*i<=N; i++) {
    if (N % i != 0) continue;
    //cout << "i: " << i << endl;
    ll cnt = 0;
    while (true) {
      if (N % i == 0) {
        cnt++;
        N /= i;
      } else {
        break;
      }
    }
    
    ll candiv = 0;
    rep(j,1,10000000) {
      cnt -= j;
      if (cnt>=0) {
        ans++;
      } else {
        break;
      }
    }
  }
  
  if (N != 1) ans++;
  
  cout << ans << endl;
}

