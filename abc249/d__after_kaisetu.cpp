#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  map<int,int> M;
  int maxv = 0;
  rep(i,0,N) {
    int tmp;
    cin >> tmp;
    maxv = max(maxv, tmp);
    if (M.count(tmp)) {
      M.at(tmp) += 1;
    } else {
      M[tmp] = 1;
    }
  }
  
  ll ans = 0;
  rep(i,1,maxv+1) {
    rep(j,1,maxv/i+1) {
      if (M.count(i) && M.count(j) && M.count(i*j)) ans += (ll)M.at(i) * M.at(j) * M.at(i*j);
    }
  }
  cout << ans << endl;
}
