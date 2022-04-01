#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  rep(i,0,N) cin >> L.at(i);
  
  sort(L.begin(), L.end());
  
  ll ans = 0LL;
  rep(i,0,N) {
    rep(j,i+1,N) {
      int lower_num = lower_bound(L.begin(), L.end(), L.at(i)+L.at(j)) - L.begin();
      
      if (lower_num - j - 1 < 0) continue;
      ans += (lower_num - j - 1);
    }
  }
  
  cout << ans << endl;
}

