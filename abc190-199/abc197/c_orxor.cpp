#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

typedef vector<vector<int>> Graph;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  ll ans = 1000000000000000000LL;
  
  for (int i=0; i < (1<<(N-1)); i++) {
    ll tans = -1;
    bool flag = false;
    ll tmp = A.at(0);
    for (int j=0; j<N-1; j++) {
      if (i & (1<<j)) {
        tmp = tmp | A.at(j+1);
      } else {
        if (!flag) {
          tans = tmp;
          flag = true;
        } else {
          tans = tans ^ tmp;
        }
        tmp = A.at(j+1);
      }
    }
    if (tans == -1) tans = tmp;
    else tans = tans ^ tmp;
    ans = min(ans, tans);
  }
  
  cout << ans << endl;
}

