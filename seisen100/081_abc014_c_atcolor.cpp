#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  vector<int> S(1000002, 0);
  rep(i,0,N) {
    int a,b;
    cin >> a >> b;
    S.at(a) += 1;
    S.at(b+1) -= 1;
  }
  
  rep(i,0,1000001) S.at(i+1) += S.at(i);
  
  int ans = 0;
  rep(i,0,1000002) ans = max(ans, S.at(i));
  cout << ans << endl;
}
