#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll mod = 1000000007LL;

void add(ll &a, ll b) {
  a += b;
  a %= mod;
}

int main() {
  ll N, L;
  cin >> N >> L;
  
  vector<ll> dp(N+1, 0);
  dp.at(0) = 1;
  dp.at(1) = 1;
  
  for (int i=2; i<=N; i++) {
    if (i-L >= 0) add(dp.at(i), dp.at(i-L));
    add(dp.at(i), dp.at(i-1));
  }
  
  cout << dp.at(N) << endl;
}

