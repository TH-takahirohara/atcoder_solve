#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll MOD = 1000000007;
string ts = "atcoder";

void add(ll &x, ll y) {
  x += y;
  x %= MOD;
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  vector<vector<ll>> vec(7, vector<ll>(N,0));
  
  rep(i,0,N) {
    if (S.at(i) == 'a') vec.at(0).at(i) = 1;
  }
  
  rep(i,1,7) {
    ll cnt = 0;
    rep(j,1,N) {
      if (vec.at(i-1).at(j-1) > 0) add(cnt, vec.at(i-1).at(j-1));
      if (S.at(j) == ts.at(i)) add(vec.at(i).at(j), cnt);
    }
  }
  
  ll ans = 0LL;
  rep(i,0,N) {
    if (vec.at(6).at(i) > 0) add(ans, vec.at(6).at(i));
  }
  
  cout << ans << endl;
}
