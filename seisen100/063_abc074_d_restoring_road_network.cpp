#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const ll INF = 1LL << 60;

int main() {
  int N;
  cin >> N;
  
  vector<vector<ll>> A(N, vector<ll>(N, INF));
  rep(i,0,N) {
    rep(j,0,N) {
      cin >> A.at(i).at(j);
    }
  }
  
  bool can = true;
  rep(k,0,N) {
    rep(i,0,N) {
      rep(j,0,N) {
        if (i==j) continue;
        if (A.at(i).at(j) > A.at(i).at(k) + A.at(k).at(j)) can = false;
      }
    }
  }
  
  if (!can) {
    cout << -1 << endl;
    return 0;
  }
  
  rep(k,0,N) {
    rep(i,0,N) {
      rep(j,0,N) {
        if (i==j) continue;
        if (i==k || j==k) continue;
        if (A.at(i).at(j) == A.at(i).at(k) + A.at(k).at(j)) {
          A.at(i).at(j) = INF;
        }
      }
    }
  }
  
  ll ans = 0;
  rep(i,0,N) {
    rep(j,0,N) {
      if (A.at(i).at(j) >= INF/2) continue;
      ans += A.at(i).at(j);
    }
  }
  
  cout << ans/2 << endl;
}
